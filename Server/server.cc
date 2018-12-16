#include "server.h"

void Server::client_work(std::shared_ptr<Socket> client) {
  client->setRcvTimeout(/*sec*/200, /*microsec*/0);
  while (true)
    try {

      std::string line = client->recv();
//      std::promise
      std::thread producer([&]() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::unique_lock<std::mutex> lock(m);
        Command *command = parser->ProcessJSONToCommand(line);
        if (command) {
          app->setCommand(command);
          notified = true;
          cond_var.notify_all();
        }
//        std:cout << "BAD INPUT" << std::endl;
        line = "BAD INPUT";
      });

      std::thread consumer([&]() {
        std::unique_lock<std::mutex> lock(m);
        while (!notified) {
          cond_var.wait(lock);
        }
        app->checkQueue();
        notified = false;
      });

      producer.join();
      consumer.join();

      std::stringstream ss;
      ss << "response ";
      ss << client->sd();
      ss << " JUST A DUMPTY RESPONSE\n";
      client->send(ss.str());

    }
    catch (const std::exception &e) {
      std::cerr << "exception: " << e.what() << std::endl;
      client->close();
      return;
    }
}
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
      std::shared_ptr<Socket> client = s.accept();
//      std::thread thr(&Server::client_work, this, client);
//      thr.detach();
      io.post(boost::bind(&Server::client_work, this, client));
    }
  } catch (const std::exception &e) {
    io.stop();
    thr_pool.join_all();
    std::cerr << e.what() << std::endl;
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
    std::cerr << e.what() << std::endl;
  }
};
