//
// Created by Иван Морозов on 02.12.2018.
//

#ifndef PUREBASE_DROP_TABLE_COMMAND_H
#define PUREBASE_DROP_TABLE_COMMAND_H

#include "../Command/command.h"
#include "../Helper/helper.h"
#include "../session_builder/session_builder.h"
#include <iostream>

class DropTableCommand : public Command{
 public:
  DropTableCommand(SessionBuilder *session, Helper *helper, std::string tableName, std::string dbName);
  void execute() override;
 private:
  SessionBuilder *_session;
  Helper *_helper;
  std::string _tableName;
  std::string _dbName;
};

#endif //PUREBASE_DROP_TABLE_COMMAND_H
