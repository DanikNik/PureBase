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
  std::string host;
  int port;

 public:
  Client() = default;
  Client(std::string _host, int _port):host(_host), port(_port){}
 ~Client() = default;

 void start();
};

#endif //PUREBASE_SIMPLE_CMD_CLIENT_H
