//
// Created by Иван Морозов on 11.11.2018.
//

#include "session.h"

Session::Session() {
  _user = new User();
}

Session::~Session() {
  delete _user;
}

void Session::create_user(std::string token) {

  if (!token.empty()) {
    _user->token = token;
  } else {
    throw std::invalid_argument("Empty string");
  }

}

void Session::set_user_name(std::string user_name) {

  if (!user_name.empty()) {
    _user->user_name = user_name;
  } else {
    throw std::invalid_argument("Empty string");
  }

}

void Session::set_permissions(int permissions) {

  _user->permissions = permissions;

}

void Session::connect() {

  _connection = true;

}

void Session::false_connect() {
  _connection = false;
}

bool Session::is_connect() {
  return _connection;
}

std::string Session::get_user_name() {
  return _user->user_name;
}

std::string Session::get_user_token() {
  return _user->token;
}

int Session::get_user_permissions() {
  return _user->permissions;
}
