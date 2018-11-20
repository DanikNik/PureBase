//
// Created by daniknik on 07.11.18.
//

#include "api_endpoint.h"
using namespace std;
void ApiEndpoint::setupRoutes() {
  using namespace Rest;
  Routes::Get(router, "/create", Routes::bind(&ApiEndpoint::doCreate, this));
  Routes::Get(router, "/read", Routes::bind(&ApiEndpoint::doRead, this));
  Routes::Get(router, "/update", Routes::bind(&ApiEndpoint::doUpdate, this));
  Routes::Get(router, "/delete", Routes::bind(&ApiEndpoint::doDelete, this));
  Routes::Get(router, "/query", Routes::bind(&ApiEndpoint::doQuery, this));
  Routes::Get(router, "/ready", Routes::bind(&ApiEndpoint::handleReady, this));
}
void ApiEndpoint::handleReady(const Rest::Request &request, Http::ResponseWriter response) {
  response.send(Http::Code::Ok, "1");
}

void ApiEndpoint::doCreate(const Rest::Request &request, Http::ResponseWriter response) {
  response.send(Http::Code::Ok, "doCreate");
}

void ApiEndpoint::doRead(const Rest::Request &request, Http::ResponseWriter response) {
  response.send(Http::Code::Ok, "doRead");
}

void ApiEndpoint::doUpdate(const Rest::Request &request, Http::ResponseWriter response) {
  response.send(Http::Code::Ok, "doUpdate");
}

void ApiEndpoint::doDelete(const Rest::Request &request, Http::ResponseWriter response) {
  response.send(Http::Code::Ok, "doDelete");
}

void ApiEndpoint::doQuery(const Rest::Request &request, Http::ResponseWriter response) {
//  Document doc;
//  doc.Parse(request.body().c_str());
//  Document resp_json;
//  Value& o = doc["actions"];
//
//  StringBuffer buffer;
//  Writer<StringBuffer> writer(buffer);
//  o.Accept(writer);
//  std::cout << buffer.GetString() << std::endl;
//  StringBuffer buffer1;
//  Writer<StringBuffer> writer1(buffer1);
//  doc.Accept(writer1);
//  response.send(Http::Code::Ok, buffer1.GetString());
//  response.send(Http::Code::Ok, request.body());

    Http::serveFile(response, "../test.json");
}

bool ApiEndpoint::init(int thr) {
  try {
    auto opts = Http::Endpoint::options()
        .threads(thr)
        .flags(Tcp::Options::InstallSignalHandler);
    httpEndpoint->init(opts);
    cout << "Cores = " << hardware_concurrency() << endl;
    cout << "Using " << thr << " threads" << endl;
    setupRoutes();
    cout << "Routes set up" << endl;
  }
  catch (...) {
    return false;
  }
}
bool ApiEndpoint::start() {
  try {
    httpEndpoint->setHandler(router.handler());
    httpEndpoint->serve();
    return true;
  }
  catch (...) {
    return false;
  }
}
bool ApiEndpoint::shutdown() {
  try {
    httpEndpoint->shutdown();
    return true;
  }
  catch (...) {
    return false;
  }
}
void ApiEndpoint::set_addr(Address addr) {
  httpEndpoint = std::make_shared<Http::Endpoint>(addr);
}
