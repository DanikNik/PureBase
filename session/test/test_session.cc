//
// Created by Иван Морозов on 11.11.2018.
//

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../session.h"

TEST(Session, create_user) {
  Session session;

  session.create_user("abcd34");

  EXPECT_EQ(session.get_user_token(), "abcd34") << "User token must be abcd34";
}

TEST(Session, create_empty_user) {
  Session session;

  ASSERT_THROW(session.create_user(""), std::invalid_argument);
}

TEST(Session, set_user_name) {
  Session session;

  session.set_user_name("Ivan");

  EXPECT_EQ(session.get_user_name(), "Ivan") << "User name must be Ivan";
}

TEST(Session, set_empty_user_name) {
  Session session;

  ASSERT_THROW(session.set_user_name(""), std::invalid_argument);
}

TEST(Session, set_user_permissions) {
  Session session;
  Permissions permissions(true, false);
  session.set_permissions(permissions);

  EXPECT_EQ(session.get_user_permissions(), permissions) << "User permissions must be 0";
}

TEST(Session, connect) {
  Session session;

  session.connect();

  EXPECT_EQ(session.is_connect(), true) << "Session connection must be true";

}

TEST(Session, false_connect) {
  Session session;

  session.false_connect();

  EXPECT_EQ(session.is_connect(), false) << "Session connection must be false";
}


int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

