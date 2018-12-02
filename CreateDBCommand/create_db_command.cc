//
// Created by Иван Морозов on 02.12.2018.
//

#include <cassert>
#include "create_db_command.h"

CreateDBCommand::CreateDBCommand(Helper *helper, std::string dbName) :
  _helper(helper),
  _dbName(dbName)
  {}

void CreateDBCommand::execute() {
  if (!_dbName.empty() && _helper) {
    std::cout << "Create Database: " << _dbName;
  } else {
    throw std::invalid_argument("Empty names or helper nullptr");
  }
}
