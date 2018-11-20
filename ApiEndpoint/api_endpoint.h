//
// Created by daniknik on 07.11.18.
//

#ifndef PUREBASE_API_ENDPOINT_H
#define PUREBASE_API_ENDPOINT_H
#include <vector>
#include <iostream>

#include <pistache/http.h>
#include <pistache/router.h>
#include <pistache/endpoint.h>

#include "rapidjson/document.h"
#include "rapidjson/writer.h"
#include "rapidjson/stringbuffer.h"
using namespace Pistache;
using namespace rapidjson;

class JSONParser {
 public:
  JSONParser() = default;
  ~JSONParser() = default;

};
//
//class Query {
// public:
//  Query() = default;
//  ~Query() = default;
//};

class ApiEndpoint {
 private:

  std::shared_ptr<Http::Endpoint> httpEndpoint;
  Rest::Router router;
//  JSONParser &parser = JSONParser();

//  Document doc;

  void setupRoutes();

  void handleReady(const Rest::Request &, Http::ResponseWriter response);

  void doCreate(const Rest::Request &, Http::ResponseWriter response);
  void doRead(const Rest::Request &, Http::ResponseWriter response);
  void doUpdate(const Rest::Request &, Http::ResponseWriter response);
  void doDelete(const Rest::Request &, Http::ResponseWriter response);
  void doQuery(const Rest::Request &, Http::ResponseWriter response);
 public:
  ApiEndpoint() = default;
  explicit ApiEndpoint(Address addr)
      : httpEndpoint(std::make_shared<Http::Endpoint>(addr)) {}

  void set_addr(Address addr);
  bool init(int thr);
  bool start();
  bool shutdown();
};

#endif //PUREBASE_API_ENDPOINT_H
