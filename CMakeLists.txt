CMAKE_MINIMUM_REQUIRED(VERSION 3.27.7)
PROJECT(Ald_TaskManager)

SET(exec_name "client")

ADD_EXECUTABLE(${exec_name} src/main.cpp)

TARGET_LINK_DIRECTORIES(${exec_name} PRIVATE ${CMAKE_SOURCE_DIR}/external/tree.hh/src/)
