//
// Created by Иван Морозов on 02.12.2018.
//

#ifndef PUREBASE_CREATE_TABLE_COMMAND_H
#define PUREBASE_CREATE_TABLE_COMMAND_H

#include "../Command/command.h"
#include "../Helper/helper.h"
#include "../session_builder/session_builder.h"
#include <vector>
#include <string>
#include <iostream>

class CreateTableCommand : public Command {
 public:
  CreateTableCommand(SessionBuilder *session, Helper *helper,
                     std::string tableName,
                     std::string dbName,
                     std::vector<std::pair<std::string, std::string>> attributes);
  void execute() override;
 private:
  Helper *_helper;
  SessionBuilder *_session;
  std::string _tableName;
  std::string _dbName;
  std::vector<std::pair<std::string, std::string>> _attributes;

};

#endif //PUREBASE_CREATE_TABLE_COMMAND_H
