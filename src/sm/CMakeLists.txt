cmake_minimum_required(VERSION 3.20)

project(Sm LANGUAGES CXX C)

# Set the output target name
set(TARGET_NAME1 Libsmiso)
set(TARGET_NAME2 Libsmeac)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Libsmiso_HEADERS ${CMAKE_SOURCE_DIR}/config.h)
set(Libsmiso_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/sm-iso.c )

set(Libsmeac_HEADERS ${CMAKE_SOURCE_DIR}/config.h)
set(Libsmeac_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/sm-eac.c )

target_include_directories(${TARGET_NAME1} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../libopensc)
target_include_directories(${TARGET_NAME2} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../sm)

add_library(${TARGET_NAME1} STATIC ${Libsmiso_HEADERS} ${Libsmiso_SOURCES})
add_library(${TARGET_NAME2} STATIC ${Libsmeac_HEADERS} ${Libsmeac_SOURCES})

target_include_directories(${TARGET_NAME} PUBLIC "C:/Program Files (x86)/Windows Kits/10/Cryptographic Provider Development Kit/Include" ${CMAKE_CURRENT_SOURCE_DIR}/src)

install(TARGETS ${TARGET_NAME1} ${TARGET_NAME2}  DESTINATION ${CMAKE_BINARY_DIR}/lib)
