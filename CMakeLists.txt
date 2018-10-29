cmake_minimum_required(VERSION 3.12)
project(PureBase)

set(CMAKE_CXX_STANDARD 17)

add_executable(PureBase main.cpp Query/query.cc Query/query.h)
target_link_libraries(PureBase pistache pthread)