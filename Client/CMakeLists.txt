cmake_minimum_required(VERSION 3.11)
project(PureBaseClient)

set(CMAKE_CXX_STANDARD 17)

set(CLIENT_LIBRARY_SOURCE
        simple_cmd_client.h
        simple_cmd_client.cc
        )

add_library(client_lib STATIC ${CLIENT_LIBRARY_SOURCE})

add_executable(purebase_client main.cpp)
target_link_libraries(purebase_client client_lib)