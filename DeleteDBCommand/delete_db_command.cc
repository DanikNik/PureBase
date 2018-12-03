//
// Created by Иван Морозов on 02.12.2018.
//

#include "delete_db_command.h"

DeleteDBCommand::DeleteDBCommand(SessionBuilder *session, Helper *helper, std::string dbName) :
  _helper(helper),
  _dbName(dbName),
  _session(session)
  {}

void DeleteDBCommand::execute() {
  if (!_dbName.empty() && _helper) {
  std::cout << "Delete Database" << _dbName;
  } else {
    throw std::invalid_argument("Empty names or helper nullptr");
  }
}
