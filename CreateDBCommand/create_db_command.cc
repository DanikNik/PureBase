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
  assert(!_dbName.empty());
  std::cout << "Create Database: " << _dbName << std::endl;
}
