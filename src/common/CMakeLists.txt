cmake_minimum_required(VERSION 3.20)

project(Common LANGUAGES CXX C)

# Set the output target name
set(TARGET_NAME Common)
set(LIBSCDL Libscdl)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(LIBSCDL_HEADERS ${CMAKE_SOURCE_DIR}/config.h ${CMAKE_CURRENT_SOURCE_DIR}/libscdl.h)
set(LIBSCDL_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/libscdl.c)

set(Common_HEADERS ${CMAKE_SOURCE_DIR}/config.h)

set(Common_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/compat_getpass.c ${CMAKE_CURRENT_SOURCE_DIR}/compat_getopt.c 
${CMAKE_CURRENT_SOURCE_DIR}/compat_strlcpy.c ${CMAKE_CURRENT_SOURCE_DIR}/compat_strlcat.c
 ${CMAKE_CURRENT_SOURCE_DIR}/simclist.c ${CMAKE_CURRENT_SOURCE_DIR}/compat_report_rangecheckfailure.c
 ${CMAKE_CURRENT_SOURCE_DIR}/compat___iob_func.c ${CMAKE_CURRENT_SOURCE_DIR}/compat_overflow.c)


add_library(${TARGET_NAME} STATIC ${Common_HEADERS} ${Common_SOURCES})
add_library(${LIBSCDL} STATIC ${LIBSCDL_HEADERS} ${LIBSCDL_SOURCES})

