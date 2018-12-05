//
// Created by Иван Морозов on 11.11.2018.
//

#ifndef PRE_WORK_USER_H
#define PRE_WORK_USER_H

#include <string>
#include "../Permissions/permissions.h"

struct User {
  std::string token;
  std::string user_name;
  Permissions permissions;
};

#endif //PRE_WORK_USER_H
