//
// Created by Иван Морозов on 11.11.2018.
//

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../create_table_command.h"
#include "../../LessonHelper/lesson_helper.h"
#include <vector>

TEST(CreateTableCommand, set_empty_helper) {
  LessonHelper *lessonHelper = nullptr;
  std::vector<std::string> attrs = {"attr1", "attr2"};
  CreateTableCommand *command = new CreateTableCommand(lessonHelper, "dbname", "tableName", attrs);

  ASSERT_THROW(command->execute(), std::invalid_argument);
}

TEST(CreateTableCommand, set_empty_dbname) {
  LessonHelper *lessonHelper;
  std::vector<std::string> attrs = {"attr1", "attr2"};
  CreateTableCommand *command = new CreateTableCommand(lessonHelper, "", "tableName", attrs);

  ASSERT_THROW(command->execute(), std::invalid_argument);
}

TEST(CreateTableCommand, set_empty_table_name) {
  LessonHelper *lessonHelper;
  std::vector<std::string> attrs = {"attr1", "attr2"};
  CreateTableCommand *command = new CreateTableCommand(lessonHelper, "dbName", "", attrs);

  ASSERT_THROW(command->execute(), std::invalid_argument);
}

TEST(CreateTableCommand, set_empty_attrs) {
  LessonHelper *lessonHelper;
  std::vector<std::string> attrs;
  CreateTableCommand *command = new CreateTableCommand(lessonHelper, "dbName", "tableName", attrs);

  ASSERT_THROW(command->execute(), std::invalid_argument);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

