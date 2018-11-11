cmake_minimum_required(VERSION 3.12)
project(PureBase)

set(CMAKE_CXX_STANDARD 17)

add_executable(PureBase main.cpp Query/query.cc Query/query.h Helper/helper.cc Helper/helper.h TeacherHelper/teacher_helper.cc
        TeacherHelper/teacher_helper.h SubjectHelper/subject_helper.cc SubjectHelper/subject_helper.h)