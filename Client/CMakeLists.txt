cmake_minimum_required(VERSION 3.11)
project(PureBaseClient)

set(CMAKE_CXX_STANDARD 17)

# Find includes in corresponding build directories
set(CMAKE_INCLUDE_CURRENT_DIR ON)
# Instruct CMake to run moc automatically when needed
set(CMAKE_AUTOMOC ON)
# Create code from a list of Qt designer ui files
set(CMAKE_AUTOUIC ON)

# Find the QtWidgets library
find_package(Qt5Widgets CONFIG REQUIRED)

# Populate a CMake variable with the sources
set(helloworld_SRCS
        mainwindow.ui
        mainwindow.cc
        main.cpp
        )

set(CLIENT_LIBRARY_SOURCE
        simple_cmd_client.h
        simple_cmd_client.cc
        )

add_library(client_lib STATIC ${CLIENT_LIBRARY_SOURCE})

add_executable(purebase_client main.cpp ${helloworld_SRCS})
target_link_libraries(purebase_client client_lib)
target_link_libraries(purebase_client Qt5::Widgets)