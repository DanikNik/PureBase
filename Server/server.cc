#include "server.h"

void Server::client_work(std::shared_ptr<Socket> client) {
  client->setRcvTimeout(/*sec*/15, /*microsec*/0);
  while (true)
    try {

      std::string line = client->recv();

      std::thread producer([&]() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::unique_lock<std::mutex> lock(m);
        Command *command = parser->ProcessJSONToCommand(line);
        app->setCommand(command);
        notified = true;
        cond_var.notify_all();
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
    Socket s;
    s.createServerSocket(port, 64);

    boost::asio::io_service::work work(io);
    for (int j = 0; j < pool_size; ++j) {
      thr_pool.create_thread(boost::bind(&boost::asio::io_service::run, &io));
    }

    while (true) {
      std::shared_ptr<Socket> client = s.accept();
//      std::thread thr(&Server::client_work, this, client);
//      thr.detach();
      io.post(boost::bind(&Server::client_work, this, client));
      cout << "iiiii" << endl;
    }
  } catch (const std::exception &e) {
    io.stop();
    thr_pool.join_all();
    std::cerr << e.what() << std::endl;
    return;
  }
};
