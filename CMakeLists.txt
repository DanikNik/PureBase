cmake_minimum_required(VERSION 3.12)
project(pre_work)

set(CMAKE_CXX_STANDARD 17)

set(SOURCE_LIB session/session.cc
        session_by_name/session_by_name.cc
        session_director/session_director.cc
        sys/sys.cc)

include_directories(session/
        session_by_name/
        session_director/
        sys/)

add_subdirectory(session/)
add_subdirectory(session_by_name/)
add_subdirectory(session_director/)
add_subdirectory(sys/)

add_library(libs STATIC ${SOURCE_LIB})

add_executable(pre_work main.cpp)

target_link_libraries(pre_work libs)

