//
// Created by Иван Морозов on 17.12.2018.
//

#ifndef PUREBASE_INSERT_ROW_COMMAND_H
#define PUREBASE_INSERT_ROW_COMMAND_H

#include "../Command/command.h"
#include "../session_builder/session_builder.h"
#include "../Helper/helper.h"
#include "../socket/socket.hpp"

class InsertRowCommand : public Command {
 public:
  InsertRowCommand(SessionBuilder *session,
                   Helper *helper,
                   std::shared_ptr<Socket> &client,
                   std::string tablename,
                   std::string dbName,
                   std::vector<std::pair<std::string, std::string>> attributes);
  void execute() override;
 private:
  SessionBuilder *_session;
  Helper *_helper;
  std::shared_ptr<Socket> _socket;
  std::string _tableName;
  std::string _dbName;
  std::vector<std::pair<std::string, std::string>> _attributes;
};

#endif //PUREBASE_INSERT_ROW_COMMAND_H
