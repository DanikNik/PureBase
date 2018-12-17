#include <utility>

//
// Created by semyon on 16.11.18.
//

#include "subject_helper.h"
#include <iostream>

SubjectHelper::SubjectHelper(std::string subjectName) {
  subject = new Subject(subjectName);
  auto id = Create(std::move(subjectName));
  subject->SetId(id);
}

SubjectHelper::SubjectHelper() {
  subject = new Subject();
}
SubjectHelper::SubjectHelper(int subjectID) {
  subject = new Subject(subjectID);
}

SubjectHelper::~SubjectHelper() {
  delete subject;
}

int SubjectHelper::Create(std::string SubjectName) {
  auto params = subject->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  std::vector<std::string> columns = {"id", "name"};
  adapt = new PostgresAdapter();
  std::string id = adapt->GetMaximumID(DEFAULT_SUBJECT_NAME);
  std::vector<std::string> values = {id, SubjectName};
  adapt->Insert(DEFAULT_SUBJECT_NAME, columns, values);
  return atoi(id.c_str());
}

void SubjectHelper::ChangeName(std::string SubjectName) {
  auto params = subject->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  auto option = std::make_pair("name", SubjectName);
  std::vector<std::pair<std::string, std::string>> columns = {option};
  auto value = std::make_pair("id", params["ID"]);
  std::vector<std::pair<std::string, std::string>> values = {value};
  adapt->Update(DEFAULT_SUBJECT_NAME, columns, values);
}

void SubjectHelper::ChangeDescription(std::string Description) {
  auto params = subject->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  auto option = std::make_pair("description", Description);
  std::vector<std::pair<std::string, std::string>> columns = {option};
  auto value = std::make_pair("id", params["ID"]);
  std::vector<std::pair<std::string, std::string>> values = {value};
  adapt->Update(DEFAULT_SUBJECT_NAME, columns, values);
}

void SubjectHelper::DeleteRow() {
  auto params = subject->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();

  auto option = std::make_pair("id", params["ID"]);
  std::vector<std::pair<std::string, std::string>> options = {option};

  adapt->Delete(DEFAULT_SUBJECT_NAME, options);
}

void SubjectHelper::ShowTables() {
  auto params = subject->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  auto result = adapt->ShowTable(DEFAULT_SUBJECT_NAME);
  for (int i = 0; i < result.size(); i++) {
    for (int j = 0; j < result[i].size(); j++)
      std::cout << result[i][j] << " ";
    std::cout << std::endl;
  }
}

std::vector<std::string> SubjectHelper::Select(std::vector<std::string> parametrs) {
  auto params = subject->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  auto idOption = std::make_pair("id", params["ID"]);
  std::vector<std::pair<std::string, std::string>> options = {idOption};
  auto result = adapt->Select(DEFAULT_SUBJECT_NAME, parametrs, options);
  return result[0];
}

std::vector<std::vector<std::string>> SubjectHelper::Select(std::vector<std::string> parametrs,
                                                            std::vector<std::pair<std::string, std::string>> options) {
  auto params = subject->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  auto result = adapt->Select(DEFAULT_SUBJECT_NAME, parametrs, options);
  return result;
}

std::vector<std::string> SubjectHelper::SelectByTag(std::vector<std::string> parametrs, std::string tag) {
  std::cout << "selecting subject by tag...";
  return {"null"};
}