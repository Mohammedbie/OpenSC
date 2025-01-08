cmake_minimum_required(VERSION 3.20)

project(Scconf LANGUAGES CXX C)

# Set the output target name
set(SCCONF_TARGET Scconf)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Specify the Lex file
set(LEX_FILE lex-parse.l)

# Specify the output file from processing the .l file
set(GENERATED_FILE ${CMAKE_CURRENT_BINARY_DIR}/lex-parse.c)

# Define a custom command to process the .l file
add_custom_command(
    OUTPUT ${GENERATED_FILE}
    COMMAND flex -o${GENERATED_FILE} ${CMAKE_SOURCE_DIR}/src/scconf/${LEX_FILE}
    MAIN_DEPENDENCY ${LEX_FILE}
    COMMENT "Generating C source from Lex file ${LEX_FILE}"
)


set(Scconf_HEADERS ${CMAKE_SOURCE_DIR}/config.h)
set(Scconf_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/scconf.c ${CMAKE_CURRENT_SOURCE_DIR}/parse.c 
${CMAKE_CURRENT_SOURCE_DIR}/write.c ${CMAKE_CURRENT_SOURCE_DIR}/sclex.c)

add_library(${SCCONF_TARGET} STATIC ${Scconf_HEADERS} ${Scconf_SOURCES})

target_include_directories(${SCCONF_TARGET} PUBLIC ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/src)
target_include_directories(${SCCONF_TARGET} PUBLIC "C:/Program Files (x86)/Windows Kits/10/Cryptographic Provider Development Kit/Include" ${CMAKE_CURRENT_SOURCE_DIR}/src)


install(TARGETS ${SCCONF_TARGET} DESTINATION ${CMAKE_BINARY_DIR}/lib)
