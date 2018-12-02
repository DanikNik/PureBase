#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../update_table_command.h"
#include "../../LessonHelper/lesson_helper.h"
#include <vector>

TEST(UpdateTableCommand, set_empty_helper) {
  LessonHelper *lessonHelper = nullptr;
  std::vector<std::string> attrs = {"attr1", "attr2"};
  UpdateTableCommand *command = new UpdateTableCommand(lessonHelper, "tableName", "dbName", attrs);

  ASSERT_THROW(command->execute(), std::invalid_argument);
}

TEST(UpdateTableCommand, set_empty_tablename) {
  LessonHelper *lessonHelper;
  std::vector<std::string> attrs = {"attr1", "attr2"};
  UpdateTableCommand *command = new UpdateTableCommand(lessonHelper, "dbname", "", attrs);

  ASSERT_THROW(command->execute(), std::invalid_argument);
}

TEST(UpdateTableCommand, set_empty_dbname) {
  LessonHelper *lessonHelper;
  std::vector<std::string> attrs = {"attr1", "attr2"};
  UpdateTableCommand *command = new UpdateTableCommand(lessonHelper, "", "tableName", attrs);

  ASSERT_THROW(command->execute(), std::invalid_argument);
}

TEST(UpdateTableCommand, set_empty_attrs) {
  LessonHelper *lessonHelper;
  std::vector<std::string> attrs;
  UpdateTableCommand *command = new UpdateTableCommand(lessonHelper, "dbname", "tableName", attrs);

  ASSERT_THROW(command->execute(), std::invalid_argument);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}



