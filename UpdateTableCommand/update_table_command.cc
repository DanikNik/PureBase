//
// Created by Иван Морозов on 02.12.2018.
//

#include "update_table_command.h"

UpdateTableCommand::UpdateTableCommand(Helper *helper,
                                       std::string tableName,
                                       std::string dbName,
                                       std::vector<std::string> attributes) :
    _helper(helper),
    _tableName(tableName),
    _dbName(dbName),
    _attributes(attributes) {}

void UpdateTableCommand::execute() {
  if (!_dbName.empty() && !_tableName.empty() && _helper && !_attributes.empty()) {
    std::cout << "Update table" << _tableName << " in Database" << _dbName;
  } else {
    throw std::invalid_argument("Empty names or helper nullptr");
  }
}
