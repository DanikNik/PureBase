cmake_minimum_required(VERSION 3.11)
project(PureBase)

set(CMAKE_CXX_STANDARD 17)


########################################################################################################################
#APPLYING LIBRARIES

find_package(GTest REQUIRED)

include_directories(${GTEST_INCLUDE_DIRS})
#include_directories(${RAPIDJSON_INCLUDE_DIRS})
#include_directories(${PISTACHE_INCLUDE_DIRS})

find_package(Boost 1.67 REQUIRED COMPONENTS system)
include_directories(${Boost_INCLUDE_DIRS})


set(SERVER_LIB_SOURCE
        Server/server.h
        Server/server.cc
        socket/socket.hpp
        socket/socket.cpp
        )
add_library(server_lib STATIC ${SERVER_LIB_SOURCE})
target_link_libraries(server_lib pthread)

set(PARSER_LIB_SOURCE
        Parser/parser.h
        Parser/parser.cc
        )
add_library(parser_lib STATIC ${PARSER_LIB_SOURCE})

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

set(COMMAND_LIB_SOURCE
        Command/command.cc
        Command/command.h)

set(APPLICATION_LIB_SOURCE
        Application/application.cc
        Application/application.h)

set(CREATE_TABLE_COMMAND_LIB_SOURCE
        CreateTableCommand/create_table_command.cc
        CreateTableCommand/create_table_command.h)

set(DROP_TABLE_COMMAND_LIB_SOURCE
        DropTableCommand/drop_table_command.cc
        DropTableCommand/drop_table_command.h)

set(UPDATE_TABLE_COMMAND_LIB_SOURCE
        UpdateTableCommand/update_table_command.cc
        UpdateTableCommand/update_table_command.h)

set(SELECT_TABLE_COMMAND_LIB_SOURCE
        SelectTableCommand/select_table_command.cc
        SelectTableCommand/select_table_command.h)

set(CREATE_DATABASE_COMMAND_LIB_SOURCE
        CreateDBCommand/create_db_command.cc
        CreateDBCommand/create_db_command.h)

set(DELETE_DATABASE_COMMAND_LIB_SOURCE
        DeleteDBCommand/delete_db_command.cc
        DeleteDBCommand/delete_db_command.h)

add_library(helper_lib STATIC ${HELPER_LIB_SOURCE})
add_library(datahelper_lib STATIC ${DATAHELPER_LIB_SOURCE})
add_library(lessonhelper_lib STATIC ${LESSONHELPER_LIB_SOURCE})
add_library(subjecthelper_lib STATIC ${SUBJECTHELPER_LIB_SOURCE})
add_library(teacherhelper_lib STATIC ${TEACHERHELPER_LIB_SOURCE})

add_library(command_lib STATIC ${COMMAND_LIB_SOURCE})
add_library(application_lib STATIC ${APPLICATION_LIB_SOURCE})
add_library(create_table_command_lib STATIC ${CREATE_TABLE_COMMAND_LIB_SOURCE})
add_library(drop_table_command_lib STATIC ${DROP_TABLE_COMMAND_LIB_SOURCE})
add_library(update_table_command_lib STATIC ${UPDATE_TABLE_COMMAND_LIB_SOURCE})
add_library(select_table_command_lib STATIC ${SELECT_TABLE_COMMAND_LIB_SOURCE})
add_library(create_db_command_lib STATIC ${CREATE_DATABASE_COMMAND_LIB_SOURCE})
add_library(delete_db_command_lib STATIC ${DELETE_DATABASE_COMMAND_LIB_SOURCE})

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

set(SYS_LIB_SOURCE
        sys/sys.h
        sys/sys.cc
        sys_base/sys_base.h)

set(PERM_LIB_SOURCE
        Permissions/permissions.cc
        Permissions/permissions.h
        PermissionsBase/permissions_base.h)

add_library(sys_lib ${SYS_LIB_SOURCE})
add_library(perm_lib ${PERM_LIB_SOURCE})

#add_subdirectory(session/)
#add_subdirectory(session_by_name/)
#add_subdirectory(session_director/)
#add_subdirectory(sys/)
########################################################################################################################
#BUILD TARGETS

add_executable(PureBase main.cpp)
target_link_libraries(PureBase
        ${Boost_LIBRARIES}

        helper_lib
        datahelper_lib
        lessonhelper_lib
        subjecthelper_lib
        teacherhelper_lib

        session_libs

        parser_lib
        server_lib
        application_lib
        sys_lib
        perm_lib

        command_lib
        create_table_command_lib
        drop_table_command_lib
        update_table_command_lib
        select_table_command_lib
        create_db_command_lib
        delete_db_command_lib
        )



#add_executable(test_endpoint Server/Tests/test_endpoint.cpp)

#target_link_libraries(test_endpoint ${GTEST_LIBRARIES} pthread)
#target_link_libraries(test_endpoint api_server_lib ${PISTACHE_LIBRARIES})

#add_executable(test_session session/test/test_session.cc)
#target_link_libraries(test_session ${GTEST_LIBRARIES} pthread)
#target_link_libraries(test_session session_libs)
#
#add_executable(test_session_director session_director/test/test_session_director.cc)
#target_link_libraries(test_session_director ${GTEST_LIBRARIES} pthread)
#target_link_libraries(test_session_director session_libs)
#
#add_executable(test_session_by_name session_by_name/test/test_session_by_name.cc)
#target_link_libraries(test_session_by_name ${GTEST_LIBRARIES} pthread)
#target_link_libraries(test_session_by_name session_libs)

#add_executable(test_sys sys/test/test_sys.cc)
#target_link_libraries(test_sys ${GTEST_LIBRARIES} pthread)
#target_link_libraries(test_sys session_libs)

add_executable(test_application application/Tests/test_application.cc)
target_link_libraries(test_application ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_application application_lib)

add_executable(test_create_table_command CreateTableCommand/Test/test_create_table_command.cc)
target_link_libraries(test_create_table_command ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_create_table_command create_table_command_lib)

add_executable(test_create_db_command CreateDBCommand/Tests/create_db_command_test.cc)
target_link_libraries(test_create_db_command ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_create_db_command create_db_command_lib)

add_executable(test_delete_db_command DeleteDBCommand/Tests/test_delete_db_command.cc)
target_link_libraries(test_delete_db_command ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_delete_db_command delete_db_command_lib)

add_executable(test_drop_table_command DropTableCommand/Tests/test_drop_table_command.cc)
target_link_libraries(test_drop_table_command ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_drop_table_command drop_table_command_lib)

add_executable(test_select_table_command SelectTableCommand/Tests/test_select_table_command.cc)
target_link_libraries(test_select_table_command ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_select_table_command select_table_command_lib)

add_executable(test_update_table_command UpdateTableCommand/Tests/test_update_table_command.cc)
target_link_libraries(test_update_table_command ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_update_table_command update_table_command_lib)
########################################################################################################################