//
// Created by Иван Морозов on 17.12.2018.
//

#include "delete_row_command.h"

DeleteRowCommand::DeleteRowCommand(SessionBuilder *session,
                                   Helper *helper,
                                   std::shared_ptr<Socket> &client,
                                   std::string tablename,
                                   std::string dbName,
                                   std::vector<std::pair<std::string, std::string>> attributes) :
    _session(session), _helper(helper), _socket(client), _tableName(std::move(tablename)), _dbName(std::move(dbName)),
    _attributes(std::move(attributes)) {}


void DeleteRowCommand::execute() {
  if (!_dbName.empty() && !_tableName.empty() && _helper && !_attributes.empty()) {
    _helper->DeleteRow(_attributes);
    _socket->send("YA UDALIL");
  } else {
    _socket->send("CHE TO CLOMALOS");
    throw std::invalid_argument("Empty names or helper nullptr");
  }
}
