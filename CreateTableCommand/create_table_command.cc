//
// Created by Иван Морозов on 02.12.2018.
//

#include "create_table_command.h"

CreateTableCommand::CreateTableCommand(Helper *helper,
                                       std::string tableName,
                                       std::string dbName,
                                       std::vector<std::string> attributes)
    : _helper(helper),
      _tableName(tableName),
      _dbName(dbName),
      _attributes(attributes) {}

void CreateTableCommand::execute() {
  std::cout << "Create Table: " << _dbName << " " << "with name: " << _tableName;
}
