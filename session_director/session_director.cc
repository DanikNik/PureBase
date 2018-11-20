//
// Created by Иван Морозов on 11.11.2018.
//

#include "session_director.h"

SessionDirector::SessionDirector(SessionBuilder *builder) : _builder(builder) {}

void SessionDirector::create_session(std::string token, SessionType type) {

    if (type == SBN) {
      _builder->set_user(token);
      _builder->set_connection();
    }
}
