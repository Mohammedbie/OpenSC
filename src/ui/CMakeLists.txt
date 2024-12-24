cmake_minimum_required(VERSION 3.20)

project(UI LANGUAGES CXX C)

# Set the output target name
set(STRINGS_TARGET Strings)
set(NOTIFY_TARGET Notify)


set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Strings_HEADERS ${CMAKE_SOURCE_DIR}/config.h)
set(Strings_SOURCES ${CMAKE_SOURCE_DIR}/src/ui/strings.c)

set(Notify_HEADERS ${CMAKE_SOURCE_DIR}/config.h)
set(Notify_SOURCES ${CMAKE_SOURCE_DIR}/src/ui/notify.c)

add_library(${STRINGS_TARGET} STATIC ${Strings_HEADERS} ${Strings_SOURCES})
add_library(${NOTIFY_TARGET} STATIC ${Notify_HEADERS} ${Notify_SOURCES})

target_include_directories(${STRINGS_TARGET} PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_include_directories(${NOTIFY_TARGET} PUBLIC ${CMAKE_SOURCE_DIR}/src)

install(TARGETS ${STRINGS_TARGET} ${NOTIFY_TARGET} DESTINATION ${CMAKE_BINARY_DIR}/lib)
