#include "server.h"
#include "time.h"

void Server::start() {
  try {
    parse_config_file("config.info");
    Socket s;
    s.createServerSocket(port, 64);
    std::cout << "[+] RUNNING SERVER ON PORT " << port << std::endl;
    std::cout << "[+] MAXIMUM CONNECTIONS AT MOMENT - " << pool_size << std::endl;

    boost::asio::io_service::work work(io);
    for (int j = 0; j < pool_size; ++j) {
      thr_pool.create_thread(boost::bind(&boost::asio::io_service::run, &io));
    }

    while (true) {
      std::shared_ptr <Socket> client = s.accept();
      io.post(boost::bind(&Server::client_work, this, client));
    }
  } catch (const std::exception &e) {
    std::cerr << "SERVER::START ERROR\n";
    std::cerr << e.what() << std::endl;
    io.stop();
    thr_pool.join_all();
    return;
  }
}

void Server::parse_config_file(std::string filepath) {
  try {
    std::ifstream config_file(filepath);
    pt::ptree tree;
    pt::read_info(config_file, tree);

    pool_size = tree.get("concurency", 1000);
    port = tree.get("port", 8090);
  } catch (pt::info_parser_error &e) {
    std::cerr << "SERVER::PARSE_CONFIG ERROR\n";
    std::cerr << e.what() << std::endl;
  }
}

//под каждый тип сообщения добавить свою абстракцию
//паттерн can-handle handle

CONNECTION_SIGNALS Server::handshake(std::shared_ptr <Socket> client) {
  try {
    usleep(5);
    client->send(std::to_string(REQUEST_HEADERS));
    auto recv = (CONNECTION_SIGNALS) stoi(client->recv());
    switch (recv) {
      case CONNECT:
        std::cout << "CLIENT " << client->sd() << " CONNECTED\n";
        return recv;
      case TRANSACTION:
        std::cout << "TRANSACTION " << client->sd() << std::endl;
        return recv;
      case FILE_UPLOAD:
        std::cout << "FILE_UPLOAD " << client->sd() << std::endl;
        return recv;
      case DISCONNECT:
        std::cout << "CLIENT " << client->sd() << " DISCONNECTED\n";
        return recv;
      default:
        std::cout << "CLIENT " << client->sd() << "ERROR in handshake" << std::endl;
        return ERROR;
    }
  } catch (std::exception &e) {
    std::cerr << "SERVER::HANDSHAKE ERROR\n";
    std::cerr << e.what() << std::endl;
    return ERROR;
  }
};


//под каждый тип сообщения добавить свою абстракцию
//паттерн can-handle handle


void Server::client_work(std::shared_ptr <Socket> client) {
  client->setRcvTimeout(/*sec*/200, /*microsec*/0);
  auto initial = handshake(client);
  if(initial!=CONNECT) return;
  bool flag = true;
  while (flag) {
    try {
      auto signal = handshake(client);
      switch (signal) {
        case TRANSACTION:
          process_transaction(client);
          break;
        case FILE_UPLOAD:
//          recieve_file(client);
          break;
        case DISCONNECT:
          client->close();
          flag = false;
          break;
        case ERROR:
          flag = false;
          break;
        default:
          break;
      }
    }
    catch (std::exception &e) {
      std::cerr << "CLIENT " << client->sd() << " ERROR in client work" << std::endl;
      std::cerr << e.what() << std::endl;
      return;
    }
  }
  std::cerr << "END OF CONVERSATION WITH CLIENT " << client->sd() << std::endl;
}

//single responsibility

void Server::process_transaction(std::shared_ptr <Socket> client) {
  try {
    std::string line = client->recv();

    std::thread producer([&]() {
      std::this_thread::sleep_for(std::chrono::seconds(1));
      std::unique_lock <std::mutex> lock(m);
      Command *command = parser->ProcessJSONToCommand(line, client);
      if (command) {
        app->setCommand(command);
        notified = true;
        cond_var.notify_all();
      }
      line = "BAD INPUT";
    });
//
    std::thread consumer([&]() {
      std::unique_lock <std::mutex> lock(m);
      while (!notified) {
        cond_var.wait(lock);
      }
      app->checkQueue();
      notified = false;
    });
//
    producer.join();
    consumer.join();
//
//    command->execute();
    std::stringstream ss;
    ss << "response ";
    ss << client->sd();
    ss << " JUST A DUMPTY RESPONSE\n";
    client->send(ss.str());
    return;
  }
  catch (const std::exception &e) {
    std::cerr << "SERVER::PROCESS_TRANSACTION ERROR\n";
    std::cerr << e.what() << std::endl;
//    client->close();
    return;
  }
}

// метод не доработан до конца
//void Server::recieve_file(std::shared_ptr <Socket> client) {
//  try {
//    auto signal = handshake(client);
//    if(signal == FILE_START) {
//      std::ofstream fout("test.jpg", std::ios::binary);
//      while (client->hasData()) //обрыв записи в файл по прибытии флага о конце файла
//        fout << client->recv();
//      std::cout << "~~~~~~\n";
//      fout.close();
//    }
//    client->send("SUCCESS");
//    return;
//  } catch (std::exception& e){
//    std::cerr << e.what() << std::endl;
//    client->send("NE SUCCESS");
//    return;
//  }
//}

