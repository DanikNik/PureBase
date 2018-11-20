cmake_minimum_required(VERSION 3.12)
project(SessionDirector)

set(SOURCE_LIB session_director.cc)

add_library(session_director STATIC ${SOURCE_LIB})

find_package( GTest REQUIRED )
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_session_director test/test_session_director.cc)

target_link_libraries(test_session_director ${GTEST_LIBRARIES})
target_link_libraries(test_session_director session_director)