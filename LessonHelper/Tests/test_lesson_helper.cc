//
// Created by semyon on 02.12.18.
//

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../lesson_helper.h"


TEST(LessonHelper, Create){
    LessonHelper LH("lesson");
    LH.Create("Frontend");
    EXPECT_EQ(0,0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}