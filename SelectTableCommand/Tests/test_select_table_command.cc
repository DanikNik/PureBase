#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../select_table_command.h"
#include "../../LessonHelper/lesson_helper.h"
#include <vector>

TEST(SelectTableCommand, set_empty_helper) {
  LessonHelper *lessonHelper = nullptr;
  std::vector<std::string> attrs = {"attr1", "attr2"};
  SelectTableCommand *command = new SelectTableCommand(lessonHelper, "tableName", "dbName", attrs);

  ASSERT_THROW(command->execute(), std::invalid_argument);
}

TEST(SelectTableCommand, set_empty_dbname) {
  LessonHelper *lessonHelper;
  std::vector<std::string> attrs = {"attr1", "attr2"};
  SelectTableCommand *command = new SelectTableCommand(lessonHelper, "tableName", "", attrs);

  ASSERT_THROW(command->execute(), std::invalid_argument);
}

TEST(SelectTableCommand, set_empty_tablename) {
  LessonHelper *lessonHelper;
  std::vector<std::string> attrs = {"attr1", "attr2"};
  SelectTableCommand *command = new SelectTableCommand(lessonHelper, "", "dbName", attrs);

  ASSERT_THROW(command->execute(), std::invalid_argument);
}

TEST(SelectTableCommand, set_empty_attrs) {
  LessonHelper *lessonHelper;
  std::vector<std::string> attrs;
  SelectTableCommand *command = new SelectTableCommand(lessonHelper, "tableName", "dbName", attrs);

  ASSERT_THROW(command->execute(), std::invalid_argument);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}



