//
// Created by Иван Морозов on 02.12.2018.
//

#include "select_table_command.h"

SelectTableCommand::SelectTableCommand(SessionBuilder *session, Helper *helper,
                                       std::string tableName,
                                       std::string dbName,
                                       std::vector<std::pair<std::string, std::string>> attributes)
    : _helper(helper), _tableName(tableName), _dbName(dbName),
      _attributes(attributes),
      _session(session) {}

void SelectTableCommand::execute() {
  if (!_dbName.empty() && !_tableName.empty() && _helper && !_attributes.empty()) {
    std::cout << "Make select from table" << _tableName << "from database" << _dbName;
  } else {
    throw std::invalid_argument("Empty names or helper nullptr");
  }
}
