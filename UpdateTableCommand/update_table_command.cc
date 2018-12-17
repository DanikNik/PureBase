//
// Created by Иван Морозов on 02.12.2018.
//

#include "update_table_command.h"

UpdateTableCommand::UpdateTableCommand(SessionBuilder *session, Helper *helper,
                                       std::string tableName,
                                       std::string dbName,
                                       std::vector<std::pair<std::string, std::string>> param,
                                       std::vector<std::pair<std::string, std::string>> attributes) :
    _helper(helper),
    _tableName(std::move(tableName)),
    _dbName(std::move(dbName)),
    _param(std::move(param)),
    _attributes(std::move(attributes)),
    _session(session)
    {}

void UpdateTableCommand::execute() {
  if (!_dbName.empty() && !_tableName.empty() && _helper && !_attributes.empty()) {
    if (_tableName == "teacher") {
      auto teacherHelper = dynamic_cast<TeacherHelper*>(_helper);
      for (const auto attribute : _attributes) {
        if (attribute.first == "name") {
          teacherHelper->ChangeName(_param, attribute.second);
        }
        if (attribute.first == "specialization") {
          teacherHelper->ChangeSpecialization(_param, attribute.second);
        }
      }
    }
  } else {
    throw std::invalid_argument("Empty names or helper nullptr");
  }
}
