project(${U8_LIBRARY})

aux_source_directory(. SRC_LIST)

# add boost
find_package(Boost REQUIRED locale)

# tests executable
set(INC_LIST ${INC_LIST} ${Boost_INCLUDE_DIRS})
set(LIB_LIST ${LIB_LIST} ${Boost_LIBRARIES})

include_directories(${INC_LIST})

add_library(${PROJECT_NAME} STATIC ${SRC_LIST})
target_link_libraries(${PROJECT_NAME} ${LIB_LIST})
