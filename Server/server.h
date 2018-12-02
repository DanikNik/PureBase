#ifndef PUREBASE_SERVER_H
#define PUREBASE_SERVER_H

#include <iostream>
#include <stdexcept>
#include <thread>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <chrono>
#include "../socket/socket.hpp"
#include "../Application/application.h"
#include "../Helper/helper.h"
#include "../DataHelper/Document_Helper/document_helper.h"
#include "../Parser/parser.h"
#include "../sys/sys.h"
using namespace std;

class Server {
 private:
  int port;
    Parser *parser;
  LessonHelper *lesson_helper;
  Application *app = new Application();
  std::queue<std::string> produced_nums;
  std::mutex m;
  std::condition_variable cond_var;
  bool notified = false;

 public:
  Server(): port(8090), app(new Application()), parser(new Parser()), helper(new DocumentHelper()){}
  Server(int _port): port(_port), app(new Application()), parser(new Parser()), helper(new DocumentHelper()){}
  virtual ~Server() = default;

  void client_work(std::shared_ptr<Socket> client) {
    client->setRcvTimeout(/*sec*/30, /*microsec*/0);
    while (true)
      try {

        std::string line = client->recv();

        std::thread producer([&]() {
          std::this_thread::sleep_for(std::chrono::seconds(1));
          std::unique_lock<std::mutex> lock(m);
          CreateDBCommand *command = new CreateDBCommand(lesson_helper, line);
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

  void start() {
    try {
      Socket s;
      s.createServerSocket(port, 25);

      pid_t pid = fork();
      if (pid > 0) {
        std::cerr << "parent: " << getpid() << std::endl;
      } else {
        std::cerr << "child: " << getpid() << std::endl;
      }


};

#endif //PUREBASE_SERVER_H
