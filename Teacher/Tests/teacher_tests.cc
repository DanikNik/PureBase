//
// Created by semyon on 16.12.18.
//

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../teacher.h"
#include <map>
#include <string>


TEST(Teacher, Teacher){//Разобраться с итератором
    Teacher th;
    auto params = th.GetParametrs();
    std::map<std::string,std::string>::iterator it = params.begin();
    std::string res = it->second;
    EXPECT_STREQ(res.c_str(),DEFAULT_DATABASE_NAME);
    it++;
    res = it->second;
    EXPECT_STREQ(res.c_str(),DEFAULT_DATABASE_TYPE);
    it++;
    res = it->second;
    EXPECT_STREQ(res.c_str(),"0");
    it++;
    res = it->second;
    EXPECT_STREQ(res.c_str(),DEFAULT_TEACHER_NAME);
    it++;
    res = it->second;
    EXPECT_STREQ(res.c_str(),DEFAULT_TEACHER_NAME);
    it++;
    res = it->second;
    EXPECT_STREQ(res.c_str(),DEFAULT_USERNAME);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}