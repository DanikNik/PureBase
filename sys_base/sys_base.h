//
// Created by Иван Морозов on 12.11.2018.
//

#ifndef PRE_WORK_SYSBASE_H
#define PRE_WORK_SYSBASE_H

class SysBase {
 public:
  virtual bool add_user(std::string token, std::string user_name, int permissions) = 0;
  virtual bool delete_user(std::string token) = 0;
  virtual bool has_user(std::string token) = 0;
  virtual std::string get_user_name(std::string token) = 0;
  virtual int get_user_permissions(std::string token) = 0;
};

#endif //PRE_WORK_SYSBASE_H
