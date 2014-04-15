project(u8)

cmake_minimum_required(VERSION 2.8)

## setup precompiled headers
#set(CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMake)
#include(cotire)

## C++
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -m64 -march=native -Wall -std=c++11 -Wl,--no-as-needed")
set(CMAKE_CXX_FLAGS_DEBUG "-O0 -g -D_DEBUG")
set(CMAKE_CXX_FLAGS_RELEASE "-Ofast -flto -funroll-loops -DNDEBUG")

## C
set(CMAKE_C_FLAGS "${CMAKE_C_FLAGS} -Wall -std=c11")
set(CMAKE_C_FLAGS_DEBUG "-O0 -g -D_DEBUG")
set(CMAKE_C_FLAGS_RELEASE "-O3 -DNDEBUG")

set(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_ARCHIVE_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/lib)
set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${PROJECT_BINARY_DIR}/)

enable_testing()


# build gtest library.
set(GTEST_ROOT ${CMAKE_SOURCE_DIR}/deps/gtest)
set(GTEST_FOUND ON)
set(GTEST_INCLUDE_DIRS ${GTEST_ROOT}/include)
set(GTEST_LIBRARY gtest)
set(GTEST_MAIN_LIBRARY gtest_main)
set(GTEST_BOTH_LIBRARIES ${GTEST_LIBRARY} ${GTEST_MAIN_LIBRARY})

add_subdirectory(deps/gtest)

# build u8 library
set(U8_INCLUDE_DIRS ${CMAKE_SOURCE_DIR}/src)
set(U8_LIBRARY ${PROJECT_NAME})

add_subdirectory(src)

# test u8 it
add_subdirectory(test)

add_test(NAME all_tests COMMAND ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}/test_u8lib)
