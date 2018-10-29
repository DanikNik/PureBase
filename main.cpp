/*
   Mathieu Stefani, 13 février 2016

   Example of an hello world server
*/


#include "pistache/endpoint.h"

using namespace Pistache;

class HelloHandler : public Http::Handler {
public:

HTTP_PROTOTYPE(HelloHandler)

    void onRequest(const Http::Request& request, Http::ResponseWriter response) {
        UNUSED(request);
        response.send(Pistache::Http::Code::Ok, "Hello World\n");
    }
};

int main() {
    Http::listenAndServe<HelloHandler>("*:9080");
}
