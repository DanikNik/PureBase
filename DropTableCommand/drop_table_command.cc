//
// Created by Иван Морозов on 02.12.2018.
//

#include "drop_table_command.h"

DropTableCommand::DropTableCommand(Helper *helper, std::string tableName, std::string dbName) :
  _helper(helper),
  _dbName(dbName),
  _tableName(tableName)
{}

void DropTableCommand::execute() {
  std::cout << "Drop table" << _tableName << "in database" << _dbName;
}
