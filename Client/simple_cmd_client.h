#include <utility>

//
// Created by daniknik on 03.12.18.
//

#ifndef PUREBASE_SIMPLE_CMD_CLIENT_H
#define PUREBASE_SIMPLE_CMD_CLIENT_H

#include <iostream>
#include <sstream>
#include <fstream>
#include <connection_headers.h>
#include "../socket/socket.hpp"

class Client {
 private:
  Socket socket;
  bool connected = false;

  std::string _host = "localhost"; //default host of PureBase server TODO deprecate
  int _port = 11337; // default port of the PureBase server
 public:
  Client() = default;
  explicit Client(std::string host, int port) : _host(std::move(host)), _port(port) {}
  ~Client() = default;

  void start();

  void process_command();
  void handshake(CONNECTION_SIGNALS signal);

  void connect();
  void disconnect();

  void transaction();
  void exit_client();

  int send_transaction(std::string path);
  int send_file(std::string path);
};

#endif //PUREBASE_SIMPLE_CMD_CLIENT_H
