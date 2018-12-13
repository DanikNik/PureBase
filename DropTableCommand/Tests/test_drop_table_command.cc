#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../drop_table_command.h"
#include "../../LessonHelper/lesson_helper.h"
#include <vector>

TEST(DropTableCommand, set_empty_helper) {
  LessonHelper *lessonHelper = nullptr;
  DropTableCommand *command = new DropTableCommand(lessonHelper, "tableName", "dbName");

  ASSERT_THROW(command->execute(), std::invalid_argument);
}

TEST(DropTableCommand, set_empty_dbname) {
  LessonHelper *lessonHelper;
  DropTableCommand *command = new DropTableCommand(lessonHelper, "tableName", "");

  ASSERT_THROW(command->execute(), std::invalid_argument);
}

TEST(DropTableCommand, set_empty_tablename) {
  LessonHelper *lessonHelper;
  DropTableCommand *command = new DropTableCommand(lessonHelper, "", "dbname");

  ASSERT_THROW(command->execute(), std::invalid_argument);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}



