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
  int send_file(std::string path);
  std::string _host = "localhost"; //default host of PureBase server TODO deprecate
  int _port = 8090; // default port of the PureBase server
  void process_command();
  Socket socket;

 public:
  Client() = default;
  explicit Client(std::string host, int port):_host(std::move(host)), _port(port){}
 ~Client() = default;

 void start();
};

#endif //PUREBASE_SIMPLE_CMD_CLIENT_H
