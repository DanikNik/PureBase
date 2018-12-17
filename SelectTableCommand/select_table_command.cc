//
// Created by Иван Морозов on 02.12.2018.
//

#include "select_table_command.h"

SelectTableCommand::SelectTableCommand(SessionBuilder *session, Helper *helper,
                                       std::string tableName,
                                       std::string dbName,
                                       std::vector<std::string> params,
                                       std::vector<std::pair<std::string, std::string>> attributes)
    : _helper(helper), _tableName(std::move(tableName)), _dbName(std::move(dbName)), _params(std::move(params)),
      _attributes(std::move(attributes)),
      _session(session) {}

void SelectTableCommand::execute() {
  if (!_dbName.empty() && !_tableName.empty() && _helper && !_attributes.empty()) {
    std::vector<std::vector<std::string>> result;
    result = _helper->Select(_params, _attributes);
    for (auto row : result) {
      for (const auto attribute : row) {
        std::cout << attribute << " ";
      }
      std::cout << std::endl;
    }
  } else {
    throw std::invalid_argument("Empty names or helper nullptr");
  }
}
