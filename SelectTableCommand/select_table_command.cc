//
// Created by Иван Морозов on 02.12.2018.
//

#include <sstream>
#include "select_table_command.h"

SelectTableCommand::SelectTableCommand(SessionBuilder *session, Helper *helper, std::shared_ptr<Socket> &socket,
                                       std::string tableName,
                                       std::string dbName,
                                       std::vector<std::string> params,
                                       std::vector<std::pair<std::string, std::string>> attributes)
    : _session(session),
      _helper(helper),
      _socket(socket),
      _tableName(std::move(tableName)),
      _dbName(std::move(dbName)),
      _params(std::move(params)),
      _attributes(std::move(attributes)) {}

void SelectTableCommand::execute() {
  if (!_dbName.empty() && !_tableName.empty() && _helper && !_attributes.empty()) {
    std::vector<std::vector<std::string>> result;
    result = _helper->Select(_params, _attributes);
    std::stringstream ss;
    for (auto row : result) {
      for (const auto attribute : row) {
        ss << attribute << " ";
      }
      ss << std::endl;
    }
    _socket->send(ss.str());
  } else {
    throw std::invalid_argument("Empty names or helper nullptr");
  }
}
