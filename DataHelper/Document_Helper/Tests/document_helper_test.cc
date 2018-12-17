//
// Created by semyon on 02.12.18.
//

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../document_helper.h"


TEST(DocumentHelper, Create){
    DocumentHelper DH("frontend_video1");
    auto id = DH.Create("frontend_video1");
    EXPECT_EQ(0,0);
}

int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}
