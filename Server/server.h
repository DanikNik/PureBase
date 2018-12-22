#ifndef PUREBASE_SERVER_H
#define PUREBASE_SERVER_H

#include <iostream>
#include <stdexcept>
#include <boost/asio.hpp>
#include <boost/thread.hpp>
#include <boost/bind.hpp>

#include <boost/property_tree/ptree.hpp>
#include <boost/property_tree/info_parser.hpp>
#include <boost/foreach.hpp>

#include <condition_variable>
#include <mutex>
#include <queue>
#include <chrono>
#include "../socket/socket.hpp"
#include "../Application/application.h"
#include "../Helper/helper.h"
#include "../LessonHelper/lesson_helper.h"
#include "../DataHelper/Video_Helper/video_helper.h"
#include "../QueryProcessor/query_processor.h"
#include "../DataHelper/Document_Helper/document_helper.h"
#include "../sys/sys.h"
#include "../CreateDBCommand/create_db_command.h"
#include "connection_headers.h"

using namespace std;

// TODO: add daemonization
// TODO: add SIGNAL support
// TODO: *refers to upper* add shutdown function
// TODO add handshake to authorize

//struct BoostThreadPool{
//
//};
// TODO отдельная реализация


class Server {
 private:
  int port;
  QueryProcessor *parser;
  Application *app;
  std::queue<std::string> produced_nums;
  std::mutex m;
  std::condition_variable cond_var;
  bool notified = false;
  int pool_size;

  boost::asio::io_service io;
  boost::thread_group thr_pool;

  void parse_config_file(std::string filepath);
  void client_work(std::shared_ptr<Socket> client);
  void process_transaction(std::shared_ptr<Socket> client);
//  void recieve_file(std::shared_ptr<Socket> client);
  CONNECTION_SIGNALS handshake(std::shared_ptr<Socket> client);
 public:
  Server() : port(8000),
             app(new Application()),
             parser(new QueryProcessor()),
             pool_size(10) {}

  explicit Server(int _port) : port(_port),
                               app(new Application()),
                               parser(new QueryProcessor()),
                               pool_size(10) {}

  virtual ~Server() {
    io.stop();
    thr_pool.join_all();
  };

  void start();
};
#endif //PUREBASE_SERVER_H
