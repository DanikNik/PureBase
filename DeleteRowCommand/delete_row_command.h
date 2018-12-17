//
// Created by Иван Морозов on 17.12.2018.
//

#include "../Command/command.h"
#include "../session_builder/session_builder.h"
#include "../Helper/helper.h"

#ifndef PUREBASE_DELETE_ROW_COMMAND_H
#define PUREBASE_DELETE_ROW_COMMAND_H

class DeleteRowCommand : public Command {
 public:
  DeleteRowCommand(SessionBuilder *session,
                   Helper *helper,
                   std::string tablename,
                   std::string dbName,
                   std::vector<std::pair<std::string, std::string>> attributes);
  void execute() override;
 private:
  SessionBuilder *_session;
  Helper *_helper;
  std::string _tableName;
  std::string _dbName;
  std::vector<std::pair<std::string, std::string>> _attributes;
};

#endif //PUREBASE_DELETE_ROW_COMMAND_H
