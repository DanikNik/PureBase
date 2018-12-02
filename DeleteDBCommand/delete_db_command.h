//
// Created by Иван Морозов on 02.12.2018.
//

#ifndef PUREBASE_DELETE_DB_COMMAND_H
#define PUREBASE_DELETE_DB_COMMAND_H

#include "../Command/command.h"
#include "../Helper/helper.h"
#include <vector>
#include <string>
#include <iostream>

class DeleteDBCommand : public Command{
 public:
  DeleteDBCommand(Helper *helper, std::string dbName);
  void execute() override;

 private:
  Helper *_helper;
  std::string _dbName;

};

#endif //PUREBASE_DELETE_DB_COMMAND_H
