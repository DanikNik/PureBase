//
// Created by Иван Морозов on 02.12.2018.
//

#ifndef PUREBASE_SELECT_TABLE_COMMAND_H
#define PUREBASE_SELECT_TABLE_COMMAND_H

#include "../Command/command.h"
#include "../Helper/helper.h"
#include "../session_builder/session_builder.h"
#include <vector>
#include <string>
#include <iostream>

const size_t ID = 0;
const size_t NAME = 1;
const size_t SPECIALIZATION = 2;

class SelectTableCommand : public Command {
 public:
  SelectTableCommand(SessionBuilder *session, Helper *helper,
                     std::string tableName,
                     std::string dbName,
                     std::vector<std::string> params,
                     std::vector<std::pair<std::string, std::string>> attributes);
  void execute() override;

 private:
  SessionBuilder *_session;
  Helper *_helper;
  std::string _tableName;
  std::string _dbName;
  std::vector<std::string> _params;
  std::vector<std::pair<std::string, std::string>> _attributes;

};

#endif //PUREBASE_SELECT_TABLE_COMMAND_H
