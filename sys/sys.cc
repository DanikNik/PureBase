//
// Created by Иван Морозов on 11.11.2018.
//

#include "sys.h"

Sys *Sys::p_instance = 0;

bool Sys::add_user(std::string token, std::string user_name, int permissions) {

  if (user_table.empty()) {
    User user;
    if (!token.empty() && !user_name.empty()) {
      user.token = token;
      user.user_name = user_name;
      user.permissions = permissions;
      user_table.emplace_back(user);

      return true;
    } else {
      throw std::invalid_argument("Empty token or user name");
    }
  } else {
    int i = 0;
    for (; user_table[i].user_name != user_name && i < user_table.size(); ++i);

    if (i == user_table.size()) {
      if (!token.empty() && !user_name.empty()) {
        User user;
        user.token = token;
        user.user_name = user_name;
        user.permissions = permissions;
        user_table.emplace_back(user);

        return true;
      } else {
        throw std::invalid_argument("Empty token or user name");
      }
    } else {
      return false;
    }
  }
}

bool Sys::delete_user(std::string token) {

  if (!token.empty()) {
    int i = 0;
    for (; user_table[i].token != token && i < user_table.size(); ++i);

    if (i != user_table.size()) {
      user_table.erase(user_table.begin() + i);

      return true;
    } else {
      return false;
    }
  } else {
    throw std::invalid_argument("Empty token");
  }
}

bool Sys::has_user(std::string token) {
  int i = 0;
  for (; user_table[i].token != token && i < user_table.size(); ++i);

  return i != user_table.size();
}

std::string Sys::get_user_name(std::string token) {

  int i = 0;
  for (; user_table[i].token != token && i < user_table.size(); ++i);

  if (i != user_table.size()) {
    return user_table[i].user_name;
  }

  return "";
}

int Sys::get_user_permissions(std::string token) {
  int i = 0;
  for (; user_table[i].token != token && i < user_table.size(); ++i);

  if (i != user_table.size()) {
    return user_table[i].permissions;
  }

  return -1;
}
