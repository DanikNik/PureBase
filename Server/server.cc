#include "server.h"

void Server::client_work(std::shared_ptr<Socket> client) {
  client->setRcvTimeout(/*sec*/30, /*microsec*/0);
  while (true)
    try {

      std::string line = client->recv();

      std::thread producer([&]() {
        std::this_thread::sleep_for(std::chrono::seconds(1));
        std::unique_lock<std::mutex> lock(m);
        CreateDBCommand *command = new CreateDBCommand(helper, line);
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

      Sys *system_table = Sys::get_instance();

      client->send("response:  " + system_table->get_user_name(line) + '\n');

    }
    catch (const std::exception &e) {
      std::cerr << "exception: " << e.what() << std::endl;
      return;
    }
}
void Server::start() {
  try {
    Socket s;
    s.createServerSocket(port, 25);

    pid_t pid = fork();
    if (pid > 0) {
      std::cerr << "parent: " << getpid() << std::endl;
    } else {
      std::cerr << "child: " << getpid() << std::endl;
    }
    while (true) {
      std::shared_ptr<Socket> client = s.accept();
      client_work(client);
    }
  }
  catch (const std::exception &e) {
    std::cerr << e.what() << std::endl;
  }
};
