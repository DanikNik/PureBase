//
// Created by Иван Морозов on 12.11.2018.
//

#ifndef PRE_WORK_SYSBASE_H
#define PRE_WORK_SYSBASE_H

#include <iostream>
#include "../Permissions/permissions.h"

class SysBase {
 public:
  virtual bool add_user(std::string token, std::string user_name, Permissions permissions) = 0;
  virtual bool delete_user(std::string token) = 0;
  virtual bool has_user(std::string token) = 0;
  virtual std::string get_user_name(std::string token) = 0;
  virtual Permissions get_user_permissions(std::string token) = 0;
};

#endif //PRE_WORK_SYSBASE_H
