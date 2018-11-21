//
// Created by Иван Морозов on 11.11.2018.
//

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../session_by_name.h"

TEST(SessionByName, get_connection) {
  //Sys *system_table = Sys::get_instance();

  //system_table->add_user("abcd", "Ivan", 0);

  //SessionByName *sbn_session;

  //sbn_session->set_user("Ivan");
  //sbn_session->set_connection();

}

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

