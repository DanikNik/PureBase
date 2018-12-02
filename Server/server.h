//
// Created by daniknik on 02.12.18.
//

#ifndef PUREBASE_SERVER_H
#define PUREBASE_SERVER_H

#include <iostream>
#include <stdexcept>
#include <thread>
#include "../socket/socket.hpp"

#include <thread>
#include <condition_variable>
#include <mutex>
#include <queue>
#include <chrono>
using namespace std;

class Server {
 private:
  int port = 8090;

  std::string query(std::string query){
    return query;
  }


 public:
  Server() = default;
  virtual ~Server() = default;

  void client_work(std::shared_ptr<Socket> client) {
    client->setRcvTimeout(/*sec*/30, /*microsec*/0);
    while (true)
      try {
        std::string line = client->recv();
        std::string ret = query(line);
        client->send("response: " + ret + '\n');
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

      while (true) {
        std::shared_ptr<Socket> client = s.accept();
        client_work(client);
      }
    }
    catch (const std::exception &e) {
      std::cerr << e.what() << std::endl;
    }
  }

};

#endif //PUREBASE_SERVER_H
