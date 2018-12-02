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
  std::cout << "Update table" << _tableName << " in Database" << _dbName;
}
