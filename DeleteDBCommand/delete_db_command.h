//
// Created by Иван Морозов on 02.12.2018.
//

#ifndef PUREBASE_DELETE_DB_COMMAND_H
#define PUREBASE_DELETE_DB_COMMAND_H

#include "../Command/command.h"
#include "../Helper/helper.h"
#include "../session_builder/session_builder.h"
#include <vector>
#include <string>
#include <iostream>

class DeleteDBCommand : public Command{
 public:
  DeleteDBCommand(SessionBuilder *session, Helper *helper, std::string dbName);
  void execute() override;

 private:
  SessionBuilder *_session;
  Helper *_helper;
  std::string _dbName;

};

#endif //PUREBASE_DELETE_DB_COMMAND_H
