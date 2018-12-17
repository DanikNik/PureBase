//
// Created by semyon on 02.12.18.
//

#include "gmock/gmock.h"
#include "gtest/gtest.h"
#include <vector>
#include <utility>
#include "../postgres_adapter.h"


/*TEST(PostgresAdapter, Create){
    std::string init_string = "dbname = purebase user = semyon";
    pqxx::connection conn(init_string);
    EXPECT_TRUE(conn.is_open());
}

TEST(PostgresAdapter, Insert){
    std::string init_string = "dbname = purebase user = semyon";
    std::string tableName = "Video";
    std::vector<std::string> columns = {"id", "name", "data"};
    std::vector<std::string> values = {"1488", "ScreenCast1", "qwerty"};
    PostgresAdapter pq(init_string);
    pq.Insert(tableName, columns, values);
    std::pair<std::string,std::string> option;
    option = std::make_pair("id","1");
    std::vector<std::pair<std::string,std::string>> options = { option };
    std::vector<std::vector<std::string>> res = pq.Select(tableName,columns,options);
    std::cout<<res[0][0]<<std::endl;
    EXPECT_EQ(1,1);
}

TEST(PostgresAdapter, Delete){
    std::string init_string = "dbname = purebase user = semyon";
    std::string tableName = "Video";
    std::pair<std::string,std::string> option;
    option  = std::make_pair("id","1");
    std::vector<std::pair<std::string,std::string>> options = { option };
    PostgresAdapter pq(init_string);
    pq.Delete(tableName, options);
    EXPECT_EQ(1,1);
}

TEST(PostgresAdapter, Update){
    std::vector<std::string> ins_columns = {"id", "name", "data"};
    std::vector<std::string> ins_values = {"1", "Screen1", "qwerty"};
    std::string init_string = "dbname = purebase user = semyon";
    std::string tableName = "Video";
    std::pair<std::string,std::string> option;
    option = std::make_pair("id","1");
    std::vector<std::pair<std::string,std::string>> options = { option };
    std::vector<std::string> columns = {"id", "name", "data"};
    std::pair<std::string,std::string> value;
    option  = std::make_pair("name","Screen2");
    std::vector<std::pair<std::string,std::string>> values = { option };
    PostgresAdapter pq(init_string);
    pq.Insert(tableName,ins_columns,ins_values);
    pq.Update(tableName, values, options);
    std::vector<std::vector<std::string>> res = pq.Select(tableName,columns,options);
    std::cout<<res[0][0]<<std::endl;
    EXPECT_EQ(1,1);
}

TEST(PostgresAdapter, GetMax){
    std::string init_string;
    init_string = "dbname = purebase user = semyon";
    PostgresAdapter pq(init_string);
    std::string i = pq.GetMaximumID("video");
    EXPECT_EQ(5,5);
}*/

TEST(PostgresAdapter, ShowTables){
    std::string init_string = "dbname = purebase user = semyon";
    PostgresAdapter * pq;
    pq = new PostgresAdapter();
    auto result = pq->ShowTable("document");
    for (int i = 0; i < result.size(); i++) {
        for(int j = 0; j< result[i].size(); j++)
            std::cout<<result[i][j]<<" ";
        std::cout<<std::endl;
    }
    delete pq;
    EXPECT_EQ(0,0);
}
int main(int argc, char **argv) {
    ::testing::InitGoogleTest(&argc, argv);
    return RUN_ALL_TESTS();
}

