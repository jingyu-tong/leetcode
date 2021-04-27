cmake_minimum_required(VERSION 3.9)
set(CMAKE_CXX_STANDARD 17)

project(leetcodecpp)
add_subdirectory(./googletest)
#add_subdirectory(1_TwoSum)
file(GLOB children RELATIVE ${CMAKE_CURRENT_LIST_DIR} ${CMAKE_CURRENT_LIST_DIR}/[0-9]*/)

FOREACH(subdir ${children})
    IF(IS_DIRECTORY ${subdir})
#        message(${subdir})
        ADD_SUBDIRECTORY(${subdir})
    endif()
ENDFOREACH()
