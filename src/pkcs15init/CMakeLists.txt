cmake_minimum_required(VERSION 3.20)

project(Pkcs15Init LANGUAGES CXX C)

# Set the output target name
set(PKCS15INIT_TARGET Pkcs15Init)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(Pkcs15Init_HEADERS 
#${CMAKE_SOURCE_DIR}/config.h
)
set(Pkcs15Init_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-lib.c ${CMAKE_CURRENT_SOURCE_DIR}/profile.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-cflex.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-cardos.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-starcos.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-oberthur.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-oberthur-awp.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-setcos.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-muscle.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-asepcos.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-rutoken.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-entersafe.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-rtecp.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-myeid.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-authentic.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-iasecc.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-epass2003.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-openpgp.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-sc-hsm.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-isoApplet.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-gids.c
)

add_library(${PKCS15INIT_TARGET} STATIC ${Pkcs15Init_HEADERS} ${Pkcs15Init_SOURCES})

target_include_directories(${PKCS15INIT_TARGET} PUBLIC ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/src)

target_include_directories(${PKCS15INIT_TARGET} PUBLIC "C:/Program Files (x86)/Windows Kits/10/Cryptographic Provider Development Kit/Include" ${CMAKE_CURRENT_SOURCE_DIR}/src)


install(TARGETS ${PKCS15INIT_TARGET} DESTINATION ${CMAKE_BINARY_DIR}/lib)
