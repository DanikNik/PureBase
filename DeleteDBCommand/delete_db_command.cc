//
// Created by Иван Морозов on 02.12.2018.
//

#include "delete_db_command.h"

DeleteDBCommand::DeleteDBCommand(Helper *helper, std::string dbName) :
  _helper(helper),
  _dbName(dbName)
  {}

void DeleteDBCommand::execute() {
  std::cout << "Delete Database" << _dbName;
}
