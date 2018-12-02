//
// Created by Иван Морозов on 02.12.2018.
//

#include "select_table_command.h"

SelectTableCommand::SelectTableCommand(Helper *helper,
                                       std::string tableName,
                                       std::string dbName,
                                       std::vector<std::string> attributes)
    : _helper(helper), _tableName(tableName), _dbName(dbName),
      _attributes(attributes) {}

void SelectTableCommand::execute() {
  std::cout << "Make select from table" << _tableName << "from database" << _dbName;
}
