//
// Created by Иван Морозов on 02.12.2018.
//

#include "drop_table_command.h"

DropTableCommand::DropTableCommand(SessionBuilder *session, Helper *helper, std::string tableName, std::string dbName) :
  _helper(helper),
  _dbName(dbName),
  _tableName(tableName),
  _session(session)
{}

void DropTableCommand::execute() {
  if (!_dbName.empty() && _helper && !_tableName.empty()) {
    std::cout << "Drop table" << _tableName << "in database" << _dbName;
  } else {
    throw std::invalid_argument("Empty names or helper nullptr");
  }
}
