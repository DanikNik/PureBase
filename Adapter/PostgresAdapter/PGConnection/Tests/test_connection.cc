//
// Created by semyon on 02.12.18.
//

#include "gmock/gmock.h"
#include "gtest/gtest.h"

#include "../pg_connection.h"


TEST(PGConnect, Create){
    std::string init_string = "dbname = purebase user = semyon";
    PGConnect conn(init_string);
    EXPECT_TRUE(conn.IsOpen());
}


int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}



