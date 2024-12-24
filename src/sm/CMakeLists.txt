cmake_minimum_required(VERSION 3.20)

project(Sm LANGUAGES CXX C)

# Set the output target name
set(SMISO_TARGET Libsmiso)
set(SMEAC_TARGET Libsmeac)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Libsmiso_HEADERS ${CMAKE_SOURCE_DIR}/config.h)
set(Libsmiso_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/sm-iso.c )

set(Libsmeac_HEADERS ${CMAKE_SOURCE_DIR}/config.h)
set(Libsmeac_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/sm-eac.c )

add_library(${SMISO_TARGET} STATIC ${Libsmiso_HEADERS} ${Libsmiso_SOURCES})
add_library(${SMEAC_TARGET} STATIC ${Libsmeac_HEADERS} ${Libsmeac_SOURCES})

target_include_directories(${SMISO_TARGET} PUBLIC ${CMAKE_SOURCE_DIR}/src)
target_include_directories(${SMEAC_TARGET} PUBLIC ${CMAKE_SOURCE_DIR}/src)

target_include_directories(${TARGET_NAME} PUBLIC "C:/Program Files (x86)/Windows Kits/10/Cryptographic Provider Development Kit/Include" ${CMAKE_CURRENT_SOURCE_DIR}/src)

install(TARGETS ${SMISO_TARGET} ${SMEAC_TARGET}  DESTINATION ${CMAKE_BINARY_DIR}/lib)
