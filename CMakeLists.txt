cmake_minimum_required(VERSION 3.12)
project(PureBase)

set(CMAKE_CXX_STANDARD 17)

########################################################################################################################
#APPLYING LIBRARIES

set(QUERIES_LIB_SOURCE
        Query/query.h
        Query/query.cc
        )
add_library(queries_lib STATIC ${QUERIES_LIB_SOURCE})

#Stub class
set(DB_MANAGER_LIB_SOURCE
        DatabaseManager/database_manager.h
        DatabaseManager/database_manager.cc
        )
add_library(database_manager_lib ${DB_MANAGER_LIB_SOURCE})

set(API_SERVER_LIB_SOURCE
        ApiEndpoint/api_endpoint.h
        ApiEndpoint/api_endpoint.cc
        )
add_library(api_server_lib ${API_SERVER_LIB_SOURCE})
link_libraries(api_server_lib pistache pthread)

find_library(GTEST_LIB NAMES gtest gmock PATHS /usr/local/lib)
find_package(RapidJSON)

########################################################################################################################
#BUILD TARGETS

add_executable(PureBase main.cpp)
target_link_libraries(PureBase)
target_link_libraries(PureBase api_server_lib)

add_executable(test_queries Query/Tests/test_queries.cpp)
target_link_libraries(test_queries ${GTEST_LIB} pthread)
target_link_libraries(test_queries queries_lib)

add_executable(test_endpoint ApiEndpoint/Tests/test_endpoint.cpp)
target_link_libraries(test_endpoint ${GTEST_LIB} pthread)
#target_link_libraries(test_endpoint api_server_lib)

########################################################################################################################