cmake_minimum_required(VERSION 3.20)

project(UI LANGUAGES CXX C)

# Set the output target name
set(TARGET_NAME1 Strings)
set(TARGET_NAME2 Notify)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Strings_HEADERS ${CMAKE_SOURCE_DIR}/config.h)
set(Strings_SOURCES ${CMAKE_SOURCE_DIR}/src/ui/strings.c)

set(Notify_HEADERS ${CMAKE_SOURCE_DIR}/config.h)
set(Notify_SOURCES ${CMAKE_SOURCE_DIR}/src/ui/notify.c)

add_library(${TARGET_NAME1} STATIC ${Strings_HEADERS} ${Strings_SOURCES})
add_library(${TARGET_NAME2} STATIC ${Notify_HEADERS} ${Notify_SOURCES})

target_include_directories(${TARGET_NAME1} PUBLIC ${CMAKE_SOURCE_DIR}/src/common)
target_include_directories(${TARGET_NAME1} PUBLIC ${CMAKE_SOURCE_DIR}/src/libopensc)

install(TARGETS ${TARGET_NAME1} ${TARGET_NAME2} DESTINATION ${CMAKE_BINARY_DIR}/lib)
