//
// Created by Иван Морозов on 02.12.2018.
//

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../application.h"

int main(int argc, char **argv) {
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();
}

