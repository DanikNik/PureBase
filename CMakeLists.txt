cmake_minimum_required(VERSION 3.11)
project(PureBase)

set(CMAKE_CXX_STANDARD 17)


########################################################################################################################
#APPLYING LIBRARIES

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

find_package(Boost 1.67 REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})


set(QUERIES_LIB_SOURCE
        Query/query.h
        Query/query.cc
        )
add_library(queries_lib STATIC ${QUERIES_LIB_SOURCE})

set(SERVER_LIB_SOURCE
        Server/server.h
        Server/server.cc
        socket/socket.hpp
        socket/socket.cpp
        )
add_library(server_lib STATIC ${SERVER_LIB_SOURCE})
target_link_libraries(server_lib pthread)

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

set(SESSION_LIB_SOURCE
        session/session.h
        session/session.cc
        session_by_name/session_by_name.h
        session_by_name/session_by_name.cc
        session_director/session_director.h
        session_director/session_director.cc
        sys/sys.h
        sys/sys.cc
        )
add_library(session_libs STATIC ${SESSION_LIB_SOURCE})

#add_subdirectory(session/)
#add_subdirectory(session_by_name/)
#add_subdirectory(session_director/)
#add_subdirectory(sys/)
########################################################################################################################
#BUILD TARGETS

add_executable(PureBase main.cpp)
target_link_libraries(PureBase
        helper_lib
        datahelper_lib
        lessonhelper_lib
        subjecthelper_lib
        teacherhelper_lib
        session_libs
        ${Boost_LIBRARIES}
        server_lib
        )

add_executable(test_queries Query/Tests/test_queries.cpp)
target_link_libraries(test_queries ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_queries queries_lib)

#add_executable(test_endpoint Server/Tests/test_endpoint.cpp)
#target_link_libraries(test_endpoint ${GTEST_LIBRARIES} pthread)
#target_link_libraries(test_endpoint api_server_lib ${PISTACHE_LIBRARIES})

add_executable(test_session session/test/test_session.cc)
target_link_libraries(test_session ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_session session_libs)

add_executable(test_session_director session_director/test/test_session_director.cc)
target_link_libraries(test_session_director ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_session_director session_libs)

add_executable(test_session_by_name session_by_name/test/test_session_by_name.cc)
target_link_libraries(test_session_by_name ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_session_by_name session_libs)

add_executable(test_sys sys/test/test_sys.cc)
target_link_libraries(test_sys ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_sys session_libs)
########################################################################################################################


