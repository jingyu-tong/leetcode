cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 17)

string(REGEX REPLACE "/$" "" CURRENT_FOLDER_ABSOLUTE ${CMAKE_CURRENT_SOURCE_DIR})
string(REGEX REPLACE ".*/(.*)" "\\1" CURRENT_FOLDER ${CURRENT_FOLDER_ABSOLUTE})
set (TARGET_NAME ${CURRENT_FOLDER})
project(${TARGET_NAME})
message(${CMAKE_CURRENT_LIST_DIR})
set(LIBRARIES
        gtest
        )
add_executable(${PROJECT_NAME} ../main.cpp ${TARGET_NAME}.cpp)
target_link_libraries(${PROJECT_NAME} ${LIBRARIES})