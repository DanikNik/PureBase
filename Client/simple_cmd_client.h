#include <utility>

//
// Created by daniknik on 03.12.18.
//

#ifndef PUREBASE_SIMPLE_CMD_CLIENT_H
#define PUREBASE_SIMPLE_CMD_CLIENT_H

#include <iostream>
#include <sstream>
#include <fstream>
#include "../socket/socket.hpp"

class Client {
 private:
  int work();
  std::string _host = "localhost";
  int _port = 8090;
  void process_command();

 public:
  Client() = default;
  explicit Client(std::string host, int port):_host(std::move(host)), _port(port){}
 ~Client() = default;

 void start();
};

#endif //PUREBASE_SIMPLE_CMD_CLIENT_H
