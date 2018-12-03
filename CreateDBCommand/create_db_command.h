//
// Created by Иван Морозов on 02.12.2018.
//

#ifndef PUREBASE_CREATE_DB_COMMAND_H
#define PUREBASE_CREATE_DB_COMMAND_H

#include "../Command/command.h"
#include "../Helper/helper.h"
#include "../session_by_name/session_by_name.h"
#include <vector>
#include <string>
#include <iostream>

class CreateDBCommand : public Command {
 public:
  CreateDBCommand(SessionBuilder *session, Helper *helper, std::string dbName);
  void execute() override;
 private:
  Helper *_helper;
  std::string _dbName;
  SessionBuilder *_session;

};

#endif //PUREBASE_CREATE_DB_COMMAND_H
