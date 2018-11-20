cmake_minimum_required(VERSION 3.12)
project(PureBase)

set(CMAKE_CXX_STANDARD 17)


########################################################################################################################
#APPLYING LIBRARIES

set(QUERIES_LIB_SOURCE
        Query/query.h
        Query/query.cc
        )
add_library(queries_lib STATIC ${QUERIES_LIB_SOURCE})

#Stub class
##set(DB_MANAGER_LIB_SOURCE
#        DatabaseManager/database_manager.h
#        DatabaseManager/database_manager.cc
#        )
##add_library(database_manager_lib ${DB_MANAGER_LIB_SOURCE})

set(API_SERVER_LIB_SOURCE
        ApiEndpoint/api_endpoint.h
        ApiEndpoint/api_endpoint.cc
        )
add_library(api_server_lib ${API_SERVER_LIB_SOURCE})
link_libraries(api_server_lib pistache pthread)

find_library(GTEST_LIB NAMES gtest gmock PATHS /usr/local/lib)
find_package(RapidJSON)

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

add_subdirectory(session/)
add_subdirectory(session_by_name/)
add_subdirectory(session_director/)
add_subdirectory(sys/)

add_library(session_libs STATIC ${SESSION_LIB_SOURCE})
########################################################################################################################
#BUILD TARGETS

add_executable(PureBase main.cpp)
target_link_libraries(PureBase)
target_link_libraries(PureBase session_libs)
target_link_libraries(PureBase helper_lib datahelper_lib lessonhelper_lib subjecthelper_lib teacherhelper_lib session_libs)
target_link_libraries(PureBase api_server_lib)

add_executable(test_queries Query/Tests/test_queries.cpp)
target_link_libraries(test_queries ${GTEST_LIB} pthread)
target_link_libraries(test_queries queries_lib)

add_executable(test_endpoint ApiEndpoint/Tests/test_endpoint.cpp)
target_link_libraries(test_endpoint ${GTEST_LIB} pthread)
#target_link_libraries(test_endpoint api_server_lib)

########################################################################################################################
