cmake_minimum_required(VERSION 3.12)
project(PureBase)

set(CMAKE_CXX_STANDARD 17)

set(QUERIES_LIB_SOURCE
        Query/query.h
        Query/query.cc
        )

add_library(queries_lib STATIC ${QUERIES_LIB_SOURCE})

add_executable( PureBase main.cpp)
target_link_libraries(PureBase pistache pthread)
target_link_libraries(PureBase queries_lib)


find_library(GTEST_LIB NAMES gtest gmock PATHS /usr/local/lib)
#

add_executable(test_queries Query/Tests/test_queries.cpp)

target_link_libraries(test_queries ${GTEST_LIB})
target_link_libraries(test_queries queries_lib)
