cmake_minimum_required(VERSION 3.20)

project(MiniDriver LANGUAGES CXX C)

# Set the output target name
set(TARGET_NAME MiniDriver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MiniDriver_HEADERS ${CMAKE_SOURCE_DIR}/config.h)
set(MiniDriver_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/minidriver.c )
set(Dependencies ${CMAKE_BIN_DIR}/src/libopensc/opensc_a.lib 
${CMAKE_BIN_DIR}/src/scconf/scconf.lib 
${CMAKE_BIN_DIR}/src/common/common.lib 
${CMAKE_BIN_DIR}/src/common/libscdl.lib 
${CMAKE_BIN_DIR}/src/ui/strings.lib 
${CMAKE_BIN_DIR}/src/ui/notify.lib 
${CMAKE_BIN_DIR}/src/sm/libsmiso.lib 
${CMAKE_BIN_DIR}/src/sm/libsmeac.lib 
${CMAKE_BIN_DIR}/src/pkcs15init/pkcs15init.lib 
ws2_32.lib gdi32.lib Comctl32.lib advapi32.lib 
Crypt32.lib User32.lib bcrypt.lib DelayImp.lib  
Rpcrt4.lib Shell32.lib Comctl32.lib Winmm.lib 
shlwapi.lib 
)

add_library(${TARGET_NAME} SHARED ${MiniDriver_SOURCES} ${MiniDriver_HEADERS})

target_include_directories(${TARGET_NAME} PUBLIC "C:/Program Files (x86)/Windows Kits/10/Cryptographic Provider Development Kit/Include" ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_options(${TARGET_NAME} PRIVATE "/DELAYLOAD:bcrypt.dll")

# Generate the .def file
set(EXPORTS_FILE ${CMAKE_CURRENT_SOURCE_DIR}/src/minidriver/minidriver.exports)
set(DEF_FILE ${CMAKE_CURRENT_BINARY_DIR}/${TARGET_NAME}.def)
add_custom_command(
    OUTPUT ${DEF_FILE}
    COMMAND echo LIBRARY ${TARGET_NAME} > ${DEF_FILE}
    COMMAND echo EXPORTS >> ${DEF_FILE}
    COMMAND type ${EXPORTS_FILE} >> ${DEF_FILE}
    DEPENDS ${EXPORTS_FILE}
    COMMENT "Generating .def file"
)

# Link the target with the .def file and libraries
target_sources(${TARGET_NAME} PRIVATE ${DEF_FILE})
set_target_properties(${TARGET_NAME} PROPERTIES LINK_FLAGS "/def:${DEF_FILE}")


target_link_libraries(${TARGET_NAME} PRIVATE ${Dependencies})

# Handle manifest embedding
add_custom_command(
    TARGET ${TARGET_NAME} POST_BUILD
    COMMAND if EXIST ${CMAKE_CURRENT_SOURCE_DIR}/src/minidriver/opensc-minidriver.dll.manifest mt -manifest ${CMAKE_CURRENT_SOURCE_DIR}/src/minidriver/opensc-minidriver.dll.manifest -outputresource:${TARGET_NAME};
    COMMENT "Embedding manifest file into DLL"
)

install(TARGETS ${TARGET_NAME} DESTINATION ${CMAKE_BINARY_DIR}/lib)
