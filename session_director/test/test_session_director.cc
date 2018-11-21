//
// Created by Иван Морозов on 11.11.2018.
//

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../session_director.h"
#include "../../session_by_name/session_by_name.h"
#include "../../sys/sys.h"

//TEST(SessionDirector, create_session) {
//
//  Sys *system_table = Sys::get_instance();
//
//  system_table->add_user("abcd", "Ivan", 0);
//  system_table->add_user("qwerty", "Name", 1);
//  system_table->add_user("thcp", "John", 5);
//
//  SessionAttribute attrib;
//  attrib.type = SBN;
//  attrib.token = "abcd";
//
//  SessionByName sba_session;
//  SessionDirector director(&sba_session);
//  director.create_session(attrib);
//  Session session;
//
//  session.create_user("abcd34");
//
//  EXPECT_EQ(session.get_user_token(), "abcd34") << "User token must be abcd34";
//}



int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

