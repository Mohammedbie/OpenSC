cmake_minimum_required(VERSION 3.20)

project(MiniDriver LANGUAGES CXX C)

# Set the output target name
set(TARGET_NAME1 opensc-pkcs11)
set(TARGET_NAME2 pkcs11-spy)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OPENSC_PKCS11_HEADERS ${CMAKE_SOURCE_DIR}/config.h)
set(OPENSC_PKCS11_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/pkcs11-global.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs11-session.c
${CMAKE_CURRENT_SOURCE_DIR}/pkcs11-object.c ${CMAKE_CURRENT_SOURCE_DIR}/misc.c ${CMAKE_CURRENT_SOURCE_DIR}/slot.c 
${CMAKE_CURRENT_SOURCE_DIR}/mechanism.c ${CMAKE_CURRENT_SOURCE_DIR}/openssl.c ${CMAKE_CURRENT_SOURCE_DIR}/framework-pkcs15.c 
${CMAKE_CURRENT_SOURCE_DIR}/framework-pkcs15init.c 
${CMAKE_CURRENT_SOURCE_DIR}/debug.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs11-display.c 
#${CMAKE_CURRENT_SOURCE_DIR}/versioninfo-pkcs11.res 
)

set(PKCS11_SPY_HEADERS ${CMAKE_SOURCE_DIR}/config.h)
set(PKCS11_SPY_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/pkcs11-spy.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs11-display.c 
# ${CMAKE_CURRENT_SOURCE_DIR}/versioninfo-pkcs11-spy.res
)

set(Dependencies1 ${CMAKE_BIN_DIR}/src/libopensc/opensc_a.lib 
${CMAKE_BIN_DIR}/src/pkcs15init/pkcs15init.lib 
${CMAKE_BIN_DIR}/src/scconf/scconf.lib 
${CMAKE_BIN_DIR}/src/common/common.lib 
${CMAKE_BIN_DIR}/src/common/libscdl.lib 
${CMAKE_BIN_DIR}/src/ui/strings.lib 
${CMAKE_BIN_DIR}/src/ui/notify.lib 
${CMAKE_BIN_DIR}/src/sm/libsmiso.lib 
${CMAKE_BIN_DIR}/src/sm/libsmeac.lib 
${CMAKE_BIN_DIR}/src/pkcs15init/pkcs15init.lib
gdi32.lib Comctl32.lib Shell32.lib user32.lib advapi32.lib ws2_32.lib Shell32.lib Comctl32.lib shlwapi.lib
)

set(Dependencies2 ${CMAKE_BIN_DIR}/src/common/libpkcs11.lib ${CMAKE_BIN_DIR}/src/common/libscdl.lib 
${CMAKE_BIN_DIR}/src/common/common.lib
gdi32.lib advapi32.lib shlwapi.lib
)

target_include_directories(${TARGET_NAME1} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../common)
target_include_directories(${TARGET_NAME2} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR}/../common)

add_library(${TARGET_NAME1} SHARED ${OPENSC_PKCS11_HEADERS} ${OPENSC_PKCS11_SOURCES})
add_library(${TARGET_NAME2} SHARED ${PKCS11_SPY_HEADERS} ${PKCS11_SPY_SOURCES})

target_include_directories(${TARGET_NAME} PUBLIC "C:/Program Files (x86)/Windows Kits/10/Cryptographic Provider Development Kit/Include" ${CMAKE_CURRENT_SOURCE_DIR}/src)

# Generate the .def file
set(DEF_FILE1 ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME1}.def)
add_custom_command(
    OUTPUT ${DEF_FILE1}
    COMMAND echo LIBRARY ${TARGET_NAME1} > ${DEF_FILE1}
    COMMAND echo EXPORTS >> ${DEF_FILE1}
    COMMAND type ${EXPORTS_FILE} >> ${DEF_FILE1}
    DEPENDS ${EXPORTS_FILE}
    COMMENT "Generating .def file"
)

# Generate the .def file
set(DEF_FILE2 ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME2}.def)
add_custom_command(
    OUTPUT ${DEF_FILE2}
    COMMAND echo LIBRARY ${TARGET_NAME2} > ${DEF_FILE2}
    COMMAND echo EXPORTS >> ${DEF_FILE2}
    COMMAND type ${EXPORTS_FILE} >> ${DEF_FILE2}
    DEPENDS ${EXPORTS_FILE}
    COMMENT "Generating .def file"
)

target_link_libraries(${TARGET_NAME1} PRIVATE ${Dependencies1})
target_link_libraries(${TARGET_NAME2} PRIVATE ${Dependencies2})

# Handle manifest embedding
add_custom_command(
    TARGET ${TARGET_NAME1} POST_BUILD
    COMMAND if EXIST ${CMAKE_CURRENT_SOURCE_DIR}/src/pkcs11/${TARGET_NAME1}.dll.manifest mt -manifest ${CMAKE_CURRENT_SOURCE_DIR}/src/pkcs11/${TARGET_NAME1}.dll.manifest mt -outputresource:${TARGET_NAME1};
    COMMENT "Embedding manifest file into DLL"
)

add_custom_command(
    TARGET ${TARGET_NAME2} POST_BUILD
    COMMAND if EXIST ${CMAKE_CURRENT_SOURCE_DIR}/src/pkcs11/${TARGET_NAME2}.dll.manifest mt -manifest ${CMAKE_CURRENT_SOURCE_DIR}/src/pkcs11/${TARGET_NAME2}.dll.manifest mt -outputresource:${TARGET_NAME2};
    COMMENT "Embedding manifest file into DLL"
)


install(TARGETS ${TARGET_NAME1} ${TARGET_NAME2} DESTINATION ${CMAKE_BINARY_DIR}/lib)
