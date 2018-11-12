//
// Created by Иван Морозов on 11.11.2018.
//

#ifndef PRE_WORK_SESSION_DIRECTOR_H
#define PRE_WORK_SESSION_DIRECTOR_H

#include "../session_builder/session_builder.h"
#include "session.h"
#include <vector>

class SessionDirector {
 public:
  SessionDirector(SessionBuilder *builder);
  void create_session(std::string token, SessionType type);

 private:
  SessionBuilder *_builder;

};

#endif //PRE_WORK_SESSION_DIRECTOR_H
