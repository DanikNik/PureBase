//
// Created by Иван Морозов on 02.12.2018.
//

#include "../Command/command.h"
#include "../Helper/helper.h"
#include "../session_builder/session_builder.h"
#include <vector>
#include <string>
#include <iostream>

#ifndef PUREBASE_UPDATE_TABLE_COMMAND_H
#define PUREBASE_UPDATE_TABLE_COMMAND_H

class UpdateTableCommand : public Command {
 public:
  UpdateTableCommand(SessionBuilder *session, Helper *helper,
                     std::string tableName,
                     std::string dbName,
                     std::vector<std::pair<std::string, std::string>> attributes);
  void execute() override;

 private:
  SessionBuilder *_session;
  Helper *_helper;
  std::string _tableName;
  std::string _dbName;
  std::vector<std::pair<std::string, std::string>> _attributes;

};

#endif //PUREBASE_UPDATE_TABLE_COMMAND_H
