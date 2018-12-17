#include <utility>

//
// Created by semyon on 16.11.18.
//

#include "teacher_helper.h"

TeacherHelper::TeacherHelper(std::string teacherName) {
  teacher = new Teacher(teacherName);
  auto id = Create(std::move(teacherName));
  teacher->SetId(id);
}

TeacherHelper::TeacherHelper() {
  teacher = new Teacher();
}

TeacherHelper::TeacherHelper(int teacher_id) {
  teacher = new Teacher(teacher_id);
}

TeacherHelper::~TeacherHelper() {
  delete teacher;
}

int TeacherHelper::Create(std::string TeacherName) {
  auto params = teacher->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  std::vector<std::string> columns = {"id", "name"};
  adapt = new PostgresAdapter();
  std::string id = adapt->GetMaximumID(DEFAULT_TEACHER_NAME);
  std::vector<std::string> values = {id, TeacherName};
  adapt->Insert(DEFAULT_TEACHER_NAME, columns, values);
  return std::stoi(id);
}

int TeacherHelper::Create(std::vector<std::pair<std::string, std::string>> values) {
  auto params = teacher->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  std::vector<std::string> columns;
  std::vector<std::string> vals;
  bool is_id = false;
  for (auto column : values) {
    if (column.first == "id") {
      columns.emplace_back("id");
      vals.emplace_back(column.second);
      is_id = true;
    }
    if (column.first == "name") {
      columns.emplace_back("name");
      vals.emplace_back(column.second);
    }
    if (column.first == "specialization") {
      columns.emplace_back("specialization");
      vals.emplace_back(column.second);
    }
  }
  adapt = new PostgresAdapter();
  std::string id = adapt->GetMaximumID(DEFAULT_TEACHER_NAME);
  if (!is_id) {
    columns.emplace_back("id");
    vals.emplace_back(id);
  }
  adapt->Insert(DEFAULT_TEACHER_NAME, columns, vals);
  return std::stoi(id);
}

void TeacherHelper::ChangeName(std::string TeacherName) {
  auto params = teacher->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  auto option = std::make_pair("name", TeacherName);
  std::vector<std::pair<std::string, std::string>> columns = {option};
  auto value = std::make_pair("id", params["ID"]);
  std::vector<std::pair<std::string, std::string>> values = {value};
  adapt->Update(DEFAULT_TEACHER_NAME, columns, values);
}

void TeacherHelper::ChangeName(std::vector<std::pair<std::string, std::string>> param, std::string TeacherName) {
  auto params = teacher->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  std::vector<std::pair<std::string, std::string>>
      values(1, std::make_pair("name", TeacherName));
  adapt->Update(DEFAULT_TEACHER_NAME, std::move(param), values);
}

void TeacherHelper::ChangeSpecialization(std::string Description) {
  auto params = teacher->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  auto option = std::make_pair("specialization", Description);
  std::vector<std::pair<std::string, std::string>> columns = {option};
  auto value = std::make_pair("id", params["ID"]);
  std::vector<std::pair<std::string, std::string>> values = {value};
  adapt->Update(DEFAULT_TEACHER_NAME, columns, values);
}

void TeacherHelper::ChangeSpecialization(std::vector<std::pair<std::string, std::string>> param,
                                         std::string Description) {
  auto params = teacher->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  std::vector<std::pair<std::string, std::string>>
      values(1, std::make_pair("specialization", Description));
  adapt->Update(DEFAULT_TEACHER_NAME, std::move(param), values);
}

void TeacherHelper::DeleteRow() {
  auto params = teacher->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();

  auto option = std::make_pair("id", params["ID"]);
  std::vector<std::pair<std::string, std::string>> options = {option};

  adapt->Delete(DEFAULT_TEACHER_NAME, options);
}

void TeacherHelper::DeleteRow(std::vector<std::pair<std::string, std::string>> options) {
  auto params = teacher->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  adapt->Delete(DEFAULT_TEACHER_NAME, options);
}

void TeacherHelper::ShowTables() {
  auto params = teacher->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  auto result = adapt->ShowTable(DEFAULT_TEACHER_NAME);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++)
      std::cout << result[i][j] << " ";
    std::cout << std::endl;
  }
}

std::vector<std::string> TeacherHelper::Select(std::vector<std::string> parametrs) {
  auto params = teacher->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  auto idOption = std::make_pair("id", params["ID"]);
  std::vector<std::pair<std::string, std::string>> options = {idOption};
  auto result = adapt->Select(DEFAULT_TEACHER_NAME, parametrs, options);
  return result[0];
}

std::vector<std::vector<std::string>> TeacherHelper::Select(std::vector<std::string> parametrs,
                                                            std::vector<std::pair<std::string, std::string>> options) {
  auto params = teacher->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  auto result = adapt->Select(DEFAULT_TEACHER_NAME, parametrs, options);
  return result;
}

std::vector<std::string> TeacherHelper::SelectByTag(std::vector<std::string> parametrs, std::string tag) {
  std::cout << "selecting by tag...";
  return {"null"};
}

std::vector<std::vector<std::string>> TeacherHelper::GetAllRows() {
  auto params = teacher->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  return adapt->ShowTable(DEFAULT_TEACHER_NAME);
}