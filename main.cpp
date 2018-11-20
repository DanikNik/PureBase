/*
   Mathieu Stefani, 13 février 2016

   Example of an hello world server
*/

#include "ApiEndpoint/api_endpoint.h"

int main(int argc, char** argv) {
  Port port(9080);
  Address addr(Ipv4::any(), port);
  ApiEndpoint endpoint(addr);
  endpoint.init(1);
  endpoint.start();
  endpoint.shutdown();
  return 0;
}
