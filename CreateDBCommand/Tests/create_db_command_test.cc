//
// Created by Иван Морозов on 11.11.2018.
//

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../create_db_command.h"
#include "../../LessonHelper/lesson_helper.h"
#include <vector>

TEST(CreateTableCommand, set_empty_helper) {
  LessonHelper *lessonHelper = nullptr;
  CreateDBCommand *command = new CreateDBCommand(lessonHelper, "dbname");

  ASSERT_THROW(command->execute(), std::invalid_argument);
}

TEST(CreateTableCommand, set_empty_dbname) {
  LessonHelper *lessonHelper;
  CreateDBCommand *command = new CreateDBCommand(lessonHelper, "");

  ASSERT_THROW(command->execute(), std::invalid_argument);
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

