//
// Created by Иван Морозов on 12.11.2018.
//

#include <tclDecls.h>
#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../sys.h"
#include "../../Permissions/permissions.h"

TEST(Sys, add_user) {
  Sys *system_table = Sys::get_instance();
  Permissions permissions(true, false);
  system_table->add_user("abcd", "Ivan", permissions);

  EXPECT_EQ(system_table->get_user_name("abcd"), "Ivan") << "User name must be Ivan";
}

TEST(Sys, get_user_name) {
  Sys *system_table = Sys::get_instance();

  EXPECT_EQ(system_table->get_user_name(""), "") << "User name must be empty string";
}

TEST(Sys, get_user_permissions) {
  Sys *system_table = Sys::get_instance();
  Permissions permissions(true, false);
  EXPECT_EQ(system_table->get_user_permissions("abcd"), permissions) << "User permissions must be 0";
}

TEST(Sys, add_empty_token_user) {
  Sys *system_table = Sys::get_instance();
  Permissions permissions(true, false);
  ASSERT_THROW(system_table->add_user("", "Mike", permissions), std::invalid_argument);
}

TEST(Sys, add_empty_user_name_user) {
  Sys *system_table = Sys::get_instance();
  Permissions permissions(true, false);
  ASSERT_THROW(system_table->add_user("abcd", "", permissions), std::invalid_argument);
}

TEST(Sys, add_empty_user) {
  Sys *system_table = Sys::get_instance();
  Permissions permissions(true, false);
  ASSERT_THROW(system_table->add_user("", "", permissions);, std::invalid_argument);
}

TEST(Sys, has_user_false) {
  Sys *system_table = Sys::get_instance();

  EXPECT_EQ(system_table->has_user("abcdd"), false) << "There is no user in the table";
}

TEST(Sys, has_user_true) {
  Sys *system_table = Sys::get_instance();

  EXPECT_EQ(system_table->has_user("abcd"), true) << "There is user in the table";
}

TEST(Sys, has_empty_true) {
  Sys *system_table = Sys::get_instance();

  EXPECT_EQ(system_table->has_user(""), false) << "There is no empty user in the table";
}

TEST(Sys, delete_user) {
  Sys *system_table = Sys::get_instance();

  EXPECT_EQ(system_table->delete_user("abcd"), true) << "Delete abcd token user";
}

TEST(Sys, delete_no_user) {
  Sys *system_table = Sys::get_instance();

  EXPECT_EQ(system_table->delete_user("abcd"), false) << "There is must to be no abcd user in the table";
}

TEST(Sys, delete_empty_string_user) {
  Sys *system_table = Sys::get_instance();

  ASSERT_THROW(system_table->delete_user(""), std::invalid_argument);
}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

