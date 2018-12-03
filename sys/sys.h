//
// Created by Иван Морозов on 11.11.2018.
//

#ifndef PRE_WORK_SYS_H
#define PRE_WORK_SYS_H

#include "../user/User.h"
#include "../sys_base/sys_base.h"
#include <vector>
#include <iostream>

class Sys : public SysBase {
 public:
  bool add_user(std::string token, std::string user_name, Permissions permissions);
  bool delete_user(std::string token);
  bool has_user(std::string token);
  std::string get_user_name(std::string token);
  Permissions get_user_permissions(std::string token);
  static Sys *get_instance() {
    if(!p_instance) p_instance = new Sys();

    return p_instance;
  }

 protected:
  Sys() = default;
 private:
  static Sys *p_instance;
  std::vector<User> user_table;

};

#endif //PRE_WORK_SYS_H
