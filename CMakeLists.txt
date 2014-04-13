project(test_u8)

cmake_minimum_required(VERSION 2.8)

## setup precompiled headers
#set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMake)
#include()

## C++
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -std=c++11 -Wl,--no-as-needed")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -D_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-O3 -DNDEBUG")

## C
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=c11")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g -D_DEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")

# build u8 lib
add_subdirectory(src)

aux_source_directory(. SRC_LIST)

find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# setup google test 
enable_testing()
set(GTEST_ROOT ${CMAKE_SOURCE_DIR}/deps/gtest)
set(GTEST_FOUND ON)
set(GTEST_INCLUDE_DIRS ${GTEST_ROOT}/include)
set(GTEST_LIBRARY gtest)
set(GTEST_MAIN_LIBRARY gtest_main)
set(GTEST_BOTH_LIBRARIES ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})

set(LIB_LIST ${LIB_LIST} ${CMAKE_SOURCE_DIR}/libs/${GTEST_LIBRARIES})
set(LIB_LIST ${LIB_LIST} ${CMAKE_SOURCE_DIR}/libs/${GTEST_MAIN_LIBRARIES})
set(LIB_LIST ${LIB_LIST} u8 pthread)

add_executable(${PROJECT_NAME} ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${LIB_LIST})
