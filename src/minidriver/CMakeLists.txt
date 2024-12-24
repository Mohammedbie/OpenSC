cmake_minimum_required(VERSION 3.20)

project(MiniDriver LANGUAGES CXX C)

# Set the output target name
set(MINIDRIVER_TARGET MiniDriver)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(MINIDRIVER_TARGET_HEADERS 
#${CMAKE_SOURCE_DIR}/config.h
)
set(MINIDRIVER_TARGET_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/minidriver.c )
set(Dependencies ${OPENSC_A_TARGET}
${SCCONF_TARGET}
${COMMON_TARGET} 
${SCDL_TARGET}
${STRINGS_TARGET}
${NOTIFY_TARGET} 
${SMISO_TARGET} 
${SMEAC_TARGET} 
${PKCS15INIT_TARGET}
ws2_32.lib gdi32.lib Comctl32.lib advapi32.lib 
Crypt32.lib User32.lib bcrypt.lib DelayImp.lib  
Rpcrt4.lib Shell32.lib Comctl32.lib Winmm.lib 
shlwapi.lib 
)

add_library(${MINIDRIVER_TARGET} SHARED ${MINIDRIVER_TARGET_SOURCES} ${MINIDRIVER_TARGET_HEADERS})

target_include_directories(${MINIDRIVER_TARGET} PUBLIC ${CMAKE_SOURCE_DIR})
target_include_directories(${MINIDRIVER_TARGET} PUBLIC "C:/Program Files (x86)/Windows Kits/10/Cryptographic Provider Development Kit/Include" ${CMAKE_CURRENT_SOURCE_DIR}/src)

target_link_options(${MINIDRIVER_TARGET} PRIVATE "/DELAYLOAD:bcrypt.dll")

# Generate the .def file
set(EXPORTS_FILE ${CMAKE_SOURCE_DIR}/src/minidriver/minidriver.exports)
set(DEF_FILE ${CMAKE_CURRENT_BINARY_DIR}/${MINIDRIVER_TARGET}.def)
add_custom_command(
    OUTPUT ${DEF_FILE}
    COMMAND echo LIBRARY ${MINIDRIVER_TARGET} > ${DEF_FILE}
    COMMAND echo EXPORTS >> ${DEF_FILE}
    COMMAND type ${EXPORTS_FILE} >> ${DEF_FILE}
    DEPENDS ${EXPORTS_FILE}
    COMMENT "Generating .def file"
)

# Link the target with the .def file and libraries
target_sources(${MINIDRIVER_TARGET} PRIVATE ${DEF_FILE})
set_target_properties(${MINIDRIVER_TARGET} PROPERTIES LINK_FLAGS "/def:${DEF_FILE}")


target_link_libraries(${MINIDRIVER_TARGET} PRIVATE ${Dependencies})

# Handle manifest embedding
add_custom_command(
    TARGET ${MINIDRIVER_TARGET} POST_BUILD
    COMMAND if EXIST ${CMAKE_CURRENT_SOURCE_DIR}/src/minidriver/opensc-minidriver.dll.manifest mt -manifest ${CMAKE_CURRENT_SOURCE_DIR}/src/minidriver/opensc-minidriver.dll.manifest -outputresource:${MINIDRIVER_TARGET};
    COMMENT "Embedding manifest file into DLL"
)

install(TARGETS ${MINIDRIVER_TARGET} DESTINATION ${CMAKE_BINARY_DIR}/lib)
