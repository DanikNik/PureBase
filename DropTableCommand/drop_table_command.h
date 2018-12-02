//
// Created by Иван Морозов on 02.12.2018.
//

#ifndef PUREBASE_DROP_TABLE_COMMAND_H
#define PUREBASE_DROP_TABLE_COMMAND_H

#include "../Command/command.h"
#include "../Helper/helper.h"
#include <iostream>

class DropTableCommand : public Command{
 public:
  DropTableCommand(Helper *helper, std::string tableName, std::string dbName);
  void execute() override;
 private:
  Helper *_helper;
  std::string _tableName;
  std::string _dbName;
};

#endif //PUREBASE_DROP_TABLE_COMMAND_H
