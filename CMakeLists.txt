cmake_minimum_required(VERSION 3.11)
project(PureBase)

set(CMAKE_CXX_STANDARD 17)


########################################################################################################################
#APPLYING LIBRARIES

find_package(GTest REQUIRED)
#find_package(RapidJSON REQUIRED)
#find_package(Pistache REQUIRED)
#include_directories(${PISTACHE_INCLUDE_DIRS})
#include_directories(${RAPIDJSON_INCLUDE_DIRS})
include_directories(${GTEST_INCLUDE_DIRS})


set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -lpqxx -lpq")

set(PQXX /usr/local/include)
find_library(PQXX_LIB REQUIRED)
find_library(PQ_LIB REQUIRED)

#set(QUERIES_LIB_SOURCE
#        Query/query.h
#        Query/query.cc
 #       )
#add_library(queries_lib STATIC ${QUERIES_LIB_SOURCE})

#set(API_SERVER_LIB_SOURCE
#        ApiEndpoint/api_endpoint.h
#        ApiEndpoint/api_endpoint.cc
#        )
#add_library(api_server_lib STATIC ${API_SERVER_LIB_SOURCE})
#target_link_libraries(api_server_lib pistache pthread)

set(HELPER_LIB_SOURCE
        Helper/helper.h
        Helper/helper.cc
        )

set(DATAHELPER_LIB_SOURCE
        DataHelper/Document_Helper/document_helper.cc
        DataHelper/Document_Helper/document_helper.h
        DataHelper/Video_Helper/video_helper.cc
        DataHelper/Video_Helper/video_helper.h
        DataHelper/data.cc
        DataHelper/data.h
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
set(ADAPTER_LIB_SOURCE
        Adapter/abstract_adapter.cc
        Adapter/abstract_adapter.h
        Adapter/PostgresAdapter/postgres_adapter.cc
        Adapter/PostgresAdapter/postgres_adapter.h
        Adapter/PostgresAdapter/PGConnection/pg_connection.cc
        Adapter/PostgresAdapter/PGConnection/pg_connection.h
        )


add_library(datahelper_lib STATIC ${DATAHELPER_LIB_SOURCE})
add_library(lessonhelper_lib STATIC ${LESSONHELPER_LIB_SOURCE})
add_library(subjecthelper_lib STATIC ${SUBJECTHELPER_LIB_SOURCE})
add_library(teacherhelper_lib STATIC ${TEACHERHELPER_LIB_SOURCE})
add_library(helper_lib STATIC ${HELPER_LIB_SOURCE})
add_library(adapter_lib STATIC ${ADAPTER_LIB_SOURCE})


#add_library(lessonhelper_testing_lib STATIC ${HELPER_LIB_SOURCE} ${LESSONHELPER_LIB_SOURCE} ${ADAPTER_LIB_SOURCE})
#set(SESSION_LIB_SOURCE
#        session/session.h
#        session/session.cc
#        session_by_name/session_by_name.h
#        session_by_name/session_by_name.cc
#        session_director/session_director.h
#        session_director/session_director.cc
#        sys/sys.h
#        sys/sys.cc
#        )
#add_library(session_libs STATIC ${SESSION_LIB_SOURCE})

#add_subdirectory(session/)
#add_subdirectory(session_by_name/)
#add_subdirectory(session_director/)
#add_subdirectory(sys/)
########################################################################################################################
#BUILD TARGETS

add_executable(PureBase main.cpp)
target_link_libraries(PureBase pthread)
target_link_libraries(PureBase
        helper_lib
        lessonhelper_lib
        subjecthelper_lib
        datahelper_lib
        teacherhelper_lib
        adapter_lib
        ${PQXX_LIB}
        ${PQ_LIB}
        #session_libs
        #api_server_lib
        )


add_executable(test_lesson_helpers LessonHelper/Tests/test_lesson_helper.cc)
target_link_libraries(test_lesson_helpers ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_lesson_helpers
        helper_lib
        lessonhelper_lib
        adapter_lib
        ${PQXX_LIB}
        ${PQ_LIB}
        )


#add_executable(test_postgres Adapter/PostgresAdapter/Tests/postgres_test.cc)
#target_link_libraries(test_postgres ${GTEST_LIBRARIES} ${PQXX_LIB} ${PQ_LIB} pthread)
#target_link_libraries(test_postgres adapter_lib)

add_executable(test_postgres_connect Adapter/PostgresAdapter/PGConnection/Tests/test_connection.cc)
target_link_libraries(test_postgres_connect ${GTEST_LIBRARIES} pthread)
target_link_libraries(test_postgres_connect
        adapter_lib
        ${PQXX_LIB}
        ${PQ_LIB}
        )

#add_executable(test_queries Query/Tests/test_queries.cpp)
#target_link_libraries(test_queries ${GTEST_LIBRARIES} pthread)
#target_link_libraries(test_queries queries_lib)

#add_executable(test_endpoint ApiEndpoint/Tests/test_endpoint.cpp)
#target_link_libraries(test_endpoint ${GTEST_LIBRARIES} pthread)
#target_link_libraries(test_endpoint api_server_lib ${PISTACHE_LIBRARIES})

#add_executable(test_session session/test/test_session.cc)
#target_link_libraries(test_session ${GTEST_LIBRARIES} pthread)
#target_link_libraries(test_session session_libs)

#add_executable(test_session_director session_director/test/test_session_director.cc)
#target_link_libraries(test_session_director ${GTEST_LIBRARIES} pthread)
#target_link_libraries(test_session_director session_libs)

#add_executable(test_session_by_name session_by_name/test/test_session_by_name.cc)
#target_link_libraries(test_session_by_name ${GTEST_LIBRARIES} pthread)
#target_link_libraries(test_session_by_name session_libs)

#add_executable(test_sys sys/test/test_sys.cc)
#target_link_libraries(test_sys ${GTEST_LIBRARIES} pthread)
#target_link_libraries(test_sys session_libs)
########################################################################################################################


