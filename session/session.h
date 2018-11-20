//
// Created by Иван Морозов on 11.11.2018.
//

#ifndef PRE_WORK_SESSION_H
#define PRE_WORK_SESSION_H

#include "../user/User.h"
#include <string>
#include <iostream>

const int EmptyTokent = -2;

// TO DO - подумать, куда можно вынести SessionType
enum SessionType {
  SBN
};

class Session {
 public:
  Session();
  void create_user(std::string token);
  void set_user_name(std::string user_name);
  void set_permissions(int permissions);
  void connect();
  void false_connect();
  bool is_connect();
  std::string get_user_name();
  std::string get_user_token();
  int get_user_permissions();
  ~Session();

 private:
  User *_user;
  bool _connection;

};

#endif //PRE_WORK_SESSION_H
