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
#include "../LessonHelper/lesson_helper.h"
#include "../DataHelper/Video_Helper/video_helper.h"
#include "../DataHelper/Document_Helper/document_helper.h"
#include "../Parser/parser.h"
#include "../sys/sys.h"
#include "../CreateDBCommand/create_db_command.h"
using namespace std;

class Server {
 private:
  int port;
  Parser *parser;
  Helper *helper;
  Application *app = new Application();
  std::queue<std::string> produced_nums;
  std::mutex m;
  std::condition_variable cond_var;
  bool notified = false;

 public:
  Server() : port(8090), app(new Application()), parser(new Parser()), helper(new DocumentHelper()) {}
  Server(int _port) : port(_port), app(new Application()), parser(new Parser()), helper(new DocumentHelper()) {}
  virtual ~Server() = default;

  void client_work(std::shared_ptr<Socket> client);

  void start();
};
#endif //PUREBASE_SERVER_H
