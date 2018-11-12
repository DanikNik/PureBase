//
// Created by Иван Морозов on 11.11.2018.
//

#ifndef PRE_WORK_SESSION_BUILDER_H
#define PRE_WORK_SESSION_BUILDER_H

#include "session.h"

class SessionBuilder {
 public:
  virtual void set_user(std::string token) = 0;
  virtual void set_connection() = 0;

  Session *get_result() {
    return _result;
  }

 protected:
  Session *_result;

};

#endif //PRE_WORK_SESSION_BUILDER_H
