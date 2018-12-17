//
// Created by Иван Морозов on 17.12.2018.
//

#include "insert_row_command.h"

InsertRowCommand::InsertRowCommand(SessionBuilder *session,
                                   Helper *helper,
                                   std::shared_ptr<Socket> &client,
                                   std::string tablename,
                                   std::string dbName,
                                   std::vector<std::pair<std::string, std::string>> attributes) :
    _session(session),
    _helper(helper),
    _socket(client),
    _tableName(std::move(tablename)),
    _dbName(std::move(dbName)),
    _attributes(std::move(attributes)) {}

void InsertRowCommand::execute() {
  if (!_dbName.empty() && !_tableName.empty() && _helper && !_attributes.empty()) {
    _helper->Create(_attributes);
    _socket->send("VSE OK");
  } else {
    _socket->send("NE OK");
    throw std::invalid_argument("Empty names or helper nullptr");
  }
}
