//
// Created by daniknik on 02.12.18.
//

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

class Server {
 private:
  int port;
  Application * app;
  Parser *parser;
  Helper* helper;

 public:
  Server(): port(8080), app(new Application()), parser(new Parser()), helper(new DocumentHelper()){}
  Server(int _port): port(_port), app(new Application()), parser(new Parser()), helper(new DocumentHelper()){}
  virtual ~Server() = default;

  void client_work(std::shared_ptr<Socket> client);

  void start();

};

#endif //PUREBASE_SERVER_H
