//
// Created by Иван Морозов on 02.12.2018.
//

#include <sstream>
#include "create_table_command.h"

CreateTableCommand::CreateTableCommand(SessionBuilder *session, Helper *helper, std::shared_ptr<Socket> &client,
                                       std::string tableName,
                                       std::string dbName,
                                       std::vector<std::pair<std::string, std::string>> attributes)
    : _session(session),
      _helper(helper),
      _socket(client),
      _tableName(tableName),
      _dbName(dbName),
      _attributes(attributes) {}

void CreateTableCommand::execute() {
  if (!_dbName.empty() && !_tableName.empty() && _helper && !_attributes.empty()) {
    std::stringstream ss;
    ss << "Create Table: " << _dbName << " " << "with name: " << _tableName;
    ss << std::endl;
    _socket->send(ss.str());
  } else {
    throw std::invalid_argument("Empty names or helper nullptr");
  }
}
