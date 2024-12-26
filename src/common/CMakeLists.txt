cmake_minimum_required(VERSION 3.20)

project(Common LANGUAGES CXX C)

# Set the output target name
set(COMMON_TARGET Common)
set(SCDL_TARGET Libscdl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(SCDL_TARGET_HEADERS ${CMAKE_SOURCE_DIR}/config.h ${CMAKE_SOURCE_DIR}/src/common/libscdl.h)
set(SCDL_TARGET_SOURCES ${CMAKE_SOURCE_DIR}/src/common/libscdl.c)

set(Common_HEADERS ${CMAKE_SOURCE_DIR}/config.h)

set(Common_SOURCES ${CMAKE_SOURCE_DIR}/src/common/compat_getpass.c ${CMAKE_SOURCE_DIR}/src/common/compat_getopt.c 
${CMAKE_SOURCE_DIR}/src/common/compat_strlcpy.c ${CMAKE_SOURCE_DIR}/src/common/compat_strlcat.c
 ${CMAKE_SOURCE_DIR}/src/common/simclist.c ${CMAKE_SOURCE_DIR}/src/common/compat_report_rangecheckfailure.c
 ${CMAKE_SOURCE_DIR}/src/common/compat___iob_func.c ${CMAKE_SOURCE_DIR}/src/common/compat_overflow.c)


add_library(${COMMON_TARGET} STATIC ${Common_HEADERS} ${Common_SOURCES})
target_include_directories(${COMMON_TARGET} PUBLIC ${CMAKE_SOURCE_DIR}/src/common)

add_library(${SCDL_TARGET} STATIC ${SCDL_TARGET_HEADERS} ${SCDL_TARGET_SOURCES})
target_include_directories(${SCDL_TARGET} PUBLIC ${CMAKE_SOURCE_DIR}/src/common)

