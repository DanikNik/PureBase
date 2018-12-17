//
// Created by Иван Морозов on 17.12.2018.
//

#include "delete_row_command.h"

DeleteRowCommand::DeleteRowCommand(SessionBuilder *session,
                                   Helper *helper,
                                   std::string tablename,
                                   std::string dbName,
                                   std::vector<std::pair<std::string, std::string>> attributes) :
    _session(session), _helper(helper), _tableName(std::move(tablename)), _dbName(std::move(dbName)),
    _attributes(std::move(attributes)) {}


void DeleteRowCommand::execute() {
  if (!_dbName.empty() && !_tableName.empty() && _helper && !_attributes.empty()) {
    _helper->DeleteRow(_attributes);
  } else {
    throw std::invalid_argument("Empty names or helper nullptr");
  }
}
