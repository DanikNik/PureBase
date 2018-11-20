//
// Created by Иван Морозов on 11.11.2018.
//

#include "session_by_name.h"

SessionByName::SessionByName() {
  _result = new Session();
}

void SessionByName::set_user(std::string token) {
  _result->create_user(token);
}

void SessionByName::set_connection() {
  Sys *system_table = Sys::get_instance();
  bool user_in_table = false;
  std::string user_token = _result->get_user_token();

  user_in_table = system_table->has_user(user_token);

  if(user_in_table) {
    _result->set_user_name(system_table->get_user_name(user_token));
    _result->set_permissions(system_table->get_user_permissions(user_token));
    _result->connect();
  } else {
    _result->false_connect();
  }
}
