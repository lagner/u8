project(test_libu8)

aux_source_directory(. SRC_LIST)

include_directories(${U8_INCLUDE_DIRS})
include_directories(${GTEST_INCLUDE_DIRS})

add_executable(${PROJECT_NAME} ${SRC_LIST})

target_link_libraries(${PROJECT_NAME} ${GTEST_BOTH_LIBRARIES} ${U8_LIBRARY})
