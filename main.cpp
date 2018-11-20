
#include "ApiEndpoint/api_endpoint.h"
//#include <iostream>
//#include "session_by_name.h"
//#include "session_director.h"
//#include "sys.h"


int main(int argc, char** argv) {
  Port port(9080);
  Address addr(Ipv4::any(), port);
  ApiEndpoint endpoint(addr);
  endpoint.init(1);
  endpoint.start();
  endpoint.shutdown();
//  Sys *system_table = Sys::get_instance();
//
//  system_table->add_user("abcd", "Ivan", 0);
//  system_table->add_user("qwerty", "Name", 1);
//  system_table->add_user("thcp", "John", 5);
//
//  SessionType type = SBN;
//  std::string token = "abcd";
//
//  SessionByName sba_session;
//  SessionDirector director(&sba_session);
//  director.create_session(token, type);
//
//  auto ses = sba_session.get_result();
//
//  if(sba_session.get_result()->is_connect()) {
//    std::cout << ses->get_user_token() << " " << ses->get_user_name() << " "
//              << ses->get_user_permissions();
//  } else {
//    std::cout << "Пользователя с такими токеном не существует" << std::endl;
//  }
  return 0;
}
