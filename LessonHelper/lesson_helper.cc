//
// Created by semyon on 16.11.18.
//

#include "lesson_helper.h"
#include <utility>

LessonHelper::LessonHelper() {
  lesson = new Lesson;
}

LessonHelper::LessonHelper(std::string lessonName) {
  lesson = new Lesson(std::move(lessonName));
}

LessonHelper::LessonHelper(int lessonID) {
  lesson = new Lesson(lessonID);
}

LessonHelper::~LessonHelper() {
  delete lesson;
}

int LessonHelper::Create(std::string LessonName) {
  auto params = lesson->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  std::vector<std::string> columns = {"id", "name"};
  adapt = new PostgresAdapter();
  std::string id = adapt->GetMaximumID("lesson");
  std::vector<std::string> values = {id, LessonName};
  adapt->Insert("lesson", columns, values);
  return atoi(id.c_str());
}

int LessonHelper::Create(std::vector<std::pair<std::string, std::string>> values) {
  auto params = lesson->GetParametrs();
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
    if (column.first == "teacher_id") {
      columns.emplace_back("teacher_id");
      vals.emplace_back(column.second);
    }
    if (column.first == "subject_id") {
      columns.emplace_back("subject_id");
      vals.emplace_back(column.second);
    }
    if (column.first == "theme") {
      columns.emplace_back("theme");
      vals.emplace_back(column.second);
    }
  }
  adapt = new PostgresAdapter();
  std::string id = adapt->GetMaximumID("lesson");
  if (!is_id) {
    columns.emplace_back("id");
    vals.emplace_back(id);
  }
  adapt->Insert("lesson", columns, vals);
  return std::stoi(id);
}

void LessonHelper::ChangeName(std::string LessonName) {
  auto params = lesson->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  auto option = std::make_pair("name", LessonName);
  std::vector<std::pair<std::string, std::string>> columns = {option};
  auto value = std::make_pair("id", params["ID"]);
  std::vector<std::pair<std::string, std::string>> values = {value};
  adapt->Update("lesson", columns, values);
}

void LessonHelper::ChangeName(std::vector<std::pair<std::string, std::string>> param, std::string LessonName) {
  auto params = lesson->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  std::vector<std::pair<std::string, std::string>>
      values(1, std::make_pair("name", LessonName));
  adapt->Update("lesson", std::move(param), values);
}

void LessonHelper::ChangeTeacher(int TeacherID) {//Добавить проверку на существование препода
  auto params = lesson->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();

  std::vector<std::string> select_columns = {"id"};
  auto select_option = std::make_pair("id", std::to_string(TeacherID));
  std::vector<std::pair<std::string, std::string>> select_options = {select_option};
  std::vector<std::vector<std::string>> tab = adapt->Select("teacher", select_columns, select_options);
  int teacher_id;
  teacher_id = atoi(tab[0][0].c_str());
  std::cout << teacher_id << std::endl;

  auto option = std::make_pair("teacher_id", tab[0][0]);
  std::vector<std::pair<std::string, std::string>> columns = {option};
  auto value = std::make_pair("id", params["ID"]);
  std::vector<std::pair<std::string, std::string>> values = {value};
  adapt->Update("lesson", columns, values);
}

void LessonHelper::ChangeTeacher(std::vector<std::pair<std::string, std::string>> param, int TeacherID) {
  auto params = lesson->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  std::vector<std::pair<std::string, std::string>>
      values(1, std::make_pair("teacher_id", std::to_string(TeacherID)));
  adapt->Update("lesson", std::move(param), values);
}

void LessonHelper::ChangeSubject(int subjectID) {
  auto params = lesson->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();

  std::vector<std::string> select_columns = {"id"};
  auto select_option = std::make_pair("id", std::to_string(subjectID));
  std::vector<std::pair<std::string, std::string>> select_options = {select_option};
  std::vector<std::vector<std::string>> tab = adapt->Select("subject", select_columns, select_options);
  int teacher_id;
  teacher_id = atoi(tab[0][0].c_str());
  std::cout << teacher_id << std::endl;

  auto option = std::make_pair("subject_id", tab[0][0]);
  std::vector<std::pair<std::string, std::string>> columns = {option};
  auto value = std::make_pair("id", params["ID"]);
  std::vector<std::pair<std::string, std::string>> values = {value};
  adapt->Update("lesson", columns, values);
}

void LessonHelper::ChangeSubject(std::vector<std::pair<std::string, std::string>> param, int subjectID) {
  auto params = lesson->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  std::vector<std::pair<std::string, std::string>>
      values(1, std::make_pair("subject_id", std::to_string(subjectID)));
  adapt->Update("lesson", std::move(param), values);
}

void LessonHelper::ChangeTheme(std::string Theme) {
  auto params = lesson->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();

  auto option = std::make_pair("theme", Theme);
  std::vector<std::pair<std::string, std::string>> columns = {option};
  auto value = std::make_pair("id", params["ID"]);
  std::vector<std::pair<std::string, std::string>> values = {value};
  adapt->Update("lesson", columns, values);
}

void LessonHelper::ChangeTheme(std::vector<std::pair<std::string, std::string>> param, std::string Theme) {
  auto params = lesson->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  std::vector<std::pair<std::string, std::string>>
      values(1, std::make_pair("theme", Theme));
  adapt->Update("lesson", std::move(param), values);
}

void LessonHelper::DeleteRow() {
  auto params = lesson->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();

  auto option = std::make_pair("id", params["ID"]);
  std::vector<std::pair<std::string, std::string>> options = {option};

  adapt->Delete("lesson", options);
}

void LessonHelper::DeleteRow(std::vector<std::pair<std::string, std::string>> options) {
  auto params = lesson->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  adapt->Delete("lesson", options);
}

void LessonHelper::ShowTables() {
  auto params = lesson->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  auto result = adapt->ShowTable("lesson");
  std::cout << "Showing tables..." << std::endl;
}

std::vector<std::string> LessonHelper::Select(std::vector<std::string> parametrs) {
  auto params = lesson->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  auto idOption = std::make_pair("id", params["ID"]);
  std::vector<std::pair<std::string, std::string>> options = {idOption};
  auto result = adapt->Select(DEFAULT_LESSON_NAME, parametrs, options);
  return result[0];
}

std::vector<std::vector<std::string>> LessonHelper::Select(std::vector<std::string> parametrs,
                                                           std::vector<std::pair<std::string, std::string>> options) {
  auto params = lesson->GetParametrs();
  std::string init_string = "dbname = " + params["DB_NAME"] + " user = " + params["USER"];
  AbstractAdapter *adapt;
  adapt = new PostgresAdapter();
  auto result = adapt->Select(DEFAULT_LESSON_NAME, parametrs, options);
  return result;
}

std::vector<std::string> LessonHelper::SelectByTag(std::vector<std::string> parametrs, std::string tag) {
  std::cout << "selecting by tag...";
  return {"null"};
}