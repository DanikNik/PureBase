cmake_minimum_required(VERSION 3.12)
project(PureBase)

set(CMAKE_CXX_STANDARD 17)

set(HELPER_LIB_SOURCE
        Helper/helper.h
        Helper/helper.cc
        )

set(DATAHELPER_LIB_SOURCE
        DataHelper/data.cc
        DataHelper/data.h
        DataHelper/Document_Helper/document_helper.cc
        DataHelper/Document_Helper/document_helper.h
        DataHelper/Video_Helper/video_helper.cc
        DataHelper/Video_Helper/video_helper.h
        )

set(LESSONHELPER_LIB_SOURCE
        LessonHelper/lesson_helper.h
        LessonHelper/lesson_helper.cc
        )

set(SUBJECTHELPER_LIB_SOURCE
        SubjectHelper/subject_helper.h
        SubjectHelper/subject_helper.cc
        )

set(TEACHERHELPER_LIB_SOURCE
        TeacherHelper/teacher_helper.cc
        TeacherHelper/teacher_helper.h
        )

add_library(helper_lib STATIC ${HELPER_LIB_SOURCE})
add_library(datahelper_lib STATIC ${DATAHELPER_LIB_SOURCE})
add_library(lessonhelper_lib STATIC ${LESSONHELPER_LIB_SOURCE})
add_library(subjecthelper_lib STATIC ${SUBJECTHELPER_LIB_SOURCE})
add_library(teacherhelper_lib STATIC ${TEACHERHELPER_LIB_SOURCE})

set(SESSION_LIB_SOURCE session/session.cc
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

add_library(session_libs STATIC ${SESSILON_LIB_SOURCE})

add_executable(PureBase main.cpp)

target_link_libraries(PureBase session_libs)
target_link_libraries(PureBase helper_lib datahelper_lib lessonhelper_lib subjecthelper_lib teacherhelper_lib session_libs)