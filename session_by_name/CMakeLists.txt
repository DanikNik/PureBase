cmake_minimum_required(VERSION 3.12)
project(SessionByName)

set(SOURCE_LIB session_by_name.cc)

add_library(session_by_name STATIC ${SOURCE_LIB})

find_package( GTest REQUIRED )
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_session_by_name test/test_session_by_name.cc)

target_link_libraries(test_session_by_name ${GTEST_LIBRARIES})
target_link_libraries(test_session_by_name session_by_name)