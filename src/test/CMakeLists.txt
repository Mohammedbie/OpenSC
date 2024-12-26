cmake_minimum_required(VERSION 3.20)

project(Tester LANGUAGES CXX C)

set(TEST_TARGET tester)

set(TEST_TARGET_SOURCES ${CMAKE_SOURCE_DIR}/src/test/main.cpp)

message(=>>>>>>>>> ${COMMON_TARGET})
set(TEST_TARGET_DEPENDENCIES Common)

add_executable(${TEST_TARGET} ${TEST_TARGET_SOURCES})

target_include_directories(${TEST_TARGET}  PUBLIC ${CMAKE_SOURCE_DIR}/src/common)

target_link_libraries(${TEST_TARGET}  PRIVATE ${TEST_TARGET_DEPENDENCIES} 
#${CMAKE_SOURCE_DIR}/build/src/common/Debug/Common.lib
)
