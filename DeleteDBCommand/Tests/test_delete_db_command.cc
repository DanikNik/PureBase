#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../delete_db_command.h"
#include "../../LessonHelper/lesson_helper.h"
#include <vector>

TEST(DeleteDBCommand, set_empty_helper) {
  LessonHelper *lessonHelper = nullptr;
  std::vector<std::string> attrs = {"attr1", "attr2"};
  DeleteDBCommand *command = new DeleteDBCommand(lessonHelper, "dbname");

  ASSERT_THROW(command->execute(), std::invalid_argument);
}

TEST(DeleteDBCommand, set_empty_dbname) {
  LessonHelper *lessonHelper;
  DeleteDBCommand *command = new DeleteDBCommand(lessonHelper, "");

  ASSERT_THROW(command->execute(), std::invalid_argument);
}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}



