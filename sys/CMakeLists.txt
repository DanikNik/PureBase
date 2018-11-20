cmake_minimum_required(VERSION 3.12)
project(Sys)

set(SOURCE_LIB sys.cc)

add_library(sys STATIC ${SOURCE_LIB})

find_package( GTest REQUIRED )
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(test_sys test/test_sys.cc)

target_link_libraries(test_sys ${GTEST_LIBRARIES})
target_link_libraries(test_sys sys)