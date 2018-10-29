//
// Created by daniknik on 29.10.18.
//


#include "gtest/gtest.h"
#include "gmock/gmock.h"


int main(int argc, char** argv) {
  // The following line must be executed to initialize Google Mock
  // (and Google Test) before running the tests.
  ::testing::InitGoogleTest(&argc, argv);
  return RUN_ALL_TESTS();

}