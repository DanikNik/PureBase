//
// Created by semyon on 02.12.18.
//

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../lesson_helper.h"


TEST(LessonHelper, Create){
    LessonHelper LH("Frontend_lesson1");
    LH.Create("Frontend_lesson1");
    EXPECT_EQ(0,0);
}

TEST(LessonHelper, ChangeName){
    LessonHelper LH(22);
    LH.ChangeName("alo2");
    EXPECT_EQ(0,0);
}

TEST(LessonHelper, ChangeTeacher){
    LessonHelper LH(22);
    LH.ChangeTeacher(3);
    EXPECT_EQ(0,0);
}

TEST(Lesson,ChangeSubject){
    LessonHelper LH(22);
    LH.ChangeSubject(1);
    EXPECT_EQ(0,0);
}

TEST(LessonHelper, ChangeTheme){
    LessonHelper LH(22);
    LH.ChangeTheme("stack");
    EXPECT_EQ(0,0);
}

TEST(LessonHelper, DeleteRow){
    LessonHelper LH(34);
    LH.DeleteRow();
    EXPECT_EQ(0,0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}