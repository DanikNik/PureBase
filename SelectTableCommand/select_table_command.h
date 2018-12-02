//
// Created by Иван Морозов on 02.12.2018.
//

#ifndef PUREBASE_SELECT_TABLE_COMMAND_H
#define PUREBASE_SELECT_TABLE_COMMAND_H

#include "../Command/command.h"
#include "../Helper/helper.h"
#include <vector>
#include <string>
#include <iostream>

class SelectTableCommand : public Command {
 public:
  SelectTableCommand(Helper *helper, std::string tableName, std::string dbName, std::vector<std::string> attributes);
  void execute() override;

 private:
  Helper *_helper;
  std::string _tableName;
  std::string _dbName;
  std::vector<std::string> _attributes;

};

#endif //PUREBASE_SELECT_TABLE_COMMAND_H
