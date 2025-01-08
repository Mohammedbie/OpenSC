cmake_minimum_required(VERSION 3.20)

project(MiniDriver LANGUAGES CXX C)

# Set the output target name
set(OPENSC_PKCS11_TARGET opensc-pkcs11)
set(PKCS11_SPY_TARGET pkcs11-spy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OPENSC_PKCS11_TARGET_HEADERS ${CMAKE_SOURCE_DIR}/config.h)
set(OPENSC_PKCS11_TARGET_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/pkcs11-global.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs11-session.c
${CMAKE_CURRENT_SOURCE_DIR}/pkcs11-object.c ${CMAKE_CURRENT_SOURCE_DIR}/misc.c ${CMAKE_CURRENT_SOURCE_DIR}/slot.c 
${CMAKE_CURRENT_SOURCE_DIR}/mechanism.c ${CMAKE_CURRENT_SOURCE_DIR}/openssl.c ${CMAKE_CURRENT_SOURCE_DIR}/framework-pkcs15.c 
${CMAKE_CURRENT_SOURCE_DIR}/framework-pkcs15init.c 
${CMAKE_CURRENT_SOURCE_DIR}/debug.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs11-display.c 
#${CMAKE_CURRENT_SOURCE_DIR}/versioninfo-pkcs11.res 
)

set(PKCS11_SPY_TARGET_HEADERS
# ${CMAKE_SOURCE_DIR}/config.h
 )
set(PKCS11_SPY_TARGET_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/pkcs11-spy.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs11-display.c 
# ${CMAKE_CURRENT_SOURCE_DIR}/versioninfo-pkcs11-spy.res
)

set(OPENSC_PKCS11_TARGET_DEPENDENCIES OpenSC_a
Pkcs15Init
Scconf
Common
Libscdl
Strings
Notify
Libsmiso 
Libsmeac
gdi32.lib Comctl32.lib Shell32.lib user32.lib advapi32.lib ws2_32.lib Shell32.lib Comctl32.lib shlwapi.lib
)

set(PKCS11_SPY_TARGET_DEPENDENCIES Libpkcs11 Libscdl Common
gdi32.lib advapi32.lib shlwapi.lib
)

add_library(${OPENSC_PKCS11_TARGET} SHARED ${OPENSC_PKCS11_TARGET_HEADERS} ${OPENSC_PKCS11_TARGET_SOURCES})
add_library(${PKCS11_SPY_TARGET} SHARED ${PKCS11_SPY_TARGET_HEADERS} ${PKCS11_SPY_TARGET_SOURCES})

target_include_directories(${OPENSC_PKCS11_TARGET} PUBLIC ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/src)
target_include_directories(${PKCS11_SPY_TARGET} PUBLIC ${CMAKE_SOURCE_DIR} ${CMAKE_SOURCE_DIR}/src)

target_include_directories(${TARGET_NAME} PUBLIC "C:/Program Files (x86)/Windows Kits/10/Cryptographic Provider Development Kit/Include" ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Generate the .def file
set(DEF_FILE1 ${CMAKE_CURRENT_BINARY_DIR}/${OPENSC_PKCS11_TARGET}.def)
add_custom_command(
    OUTPUT ${DEF_FILE1}
    COMMAND echo LIBRARY ${OPENSC_PKCS11_TARGET} > ${DEF_FILE1}
    COMMAND echo EXPORTS >> ${DEF_FILE1}
    COMMAND type ${EXPORTS_FILE} >> ${DEF_FILE1}
    DEPENDS ${EXPORTS_FILE}
    COMMENT "Generating .def file"
)

# Generate the .def file
set(DEF_FILE2 ${CMAKE_CURRENT_BINARY_DIR}/${PKCS11_SPY_TARGET}.def)
add_custom_command(
    OUTPUT ${DEF_FILE2}
    COMMAND echo LIBRARY ${PKCS11_SPY_TARGET} > ${DEF_FILE2}
    COMMAND echo EXPORTS >> ${DEF_FILE2}
    COMMAND type ${EXPORTS_FILE} >> ${DEF_FILE2}
    DEPENDS ${EXPORTS_FILE}
    COMMENT "Generating .def file"
)

target_link_libraries(${OPENSC_PKCS11_TARGET} PRIVATE ${OPENSC_PKCS11_TARGET_DEPENDENCIES})
target_link_libraries(${PKCS11_SPY_TARGET} PRIVATE ${PKCS11_SPY_TARGET_DEPENDENCIES})

# Handle manifest embedding
add_custom_command(
    TARGET ${OPENSC_PKCS11_TARGET} POST_BUILD
    COMMAND if EXIST ${CMAKE_CURRENT_SOURCE_DIR}/src/pkcs11/${OPENSC_PKCS11_TARGET}.dll.manifest mt -manifest ${CMAKE_CURRENT_SOURCE_DIR}/src/pkcs11/${OPENSC_PKCS11_TARGET}.dll.manifest mt -outputresource:${OPENSC_PKCS11_TARGET};
    COMMENT "Embedding manifest file into DLL"
)

add_custom_command(
    TARGET ${PKCS11_SPY_TARGET} POST_BUILD
    COMMAND if EXIST ${CMAKE_CURRENT_SOURCE_DIR}/src/pkcs11/${PKCS11_SPY_TARGET}.dll.manifest mt -manifest ${CMAKE_CURRENT_SOURCE_DIR}/src/pkcs11/${PKCS11_SPY_TARGET}.dll.manifest mt -outputresource:${PKCS11_SPY_TARGET};
    COMMENT "Embedding manifest file into DLL"
)


install(TARGETS ${OPENSC_PKCS11_TARGET} ${PKCS11_SPY_TARGET} DESTINATION ${CMAKE_BINARY_DIR}/lib)
