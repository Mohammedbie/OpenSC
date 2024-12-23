cmake_minimum_required(VERSION 3.20)

project(OpenSC LANGUAGES CXX C)

# Set the output target name
set(TARGET_NAME OpenSC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

set(OpenSC_HEADERS ${CMAKE_SOURCE_DIR}/config.h)
set(OpenSC_SOURCES ${CMAKE_CURRENT_SOURCE_DIR}/sc.c ${CMAKE_CURRENT_SOURCE_DIR}/ctx.c ${CMAKE_CURRENT_SOURCE_DIR}/log.c
${CMAKE_CURRENT_SOURCE_DIR}/errors.c ${CMAKE_CURRENT_SOURCE_DIR}/asn1.c ${CMAKE_CURRENT_SOURCE_DIR}/base64.c
${CMAKE_CURRENT_SOURCE_DIR}/sec.c ${CMAKE_CURRENT_SOURCE_DIR}/card.c ${CMAKE_CURRENT_SOURCE_DIR}/iso7816.c 
${CMAKE_CURRENT_SOURCE_DIR}/dir.c ${CMAKE_CURRENT_SOURCE_DIR}/ef-atr.c ${CMAKE_CURRENT_SOURCE_DIR}/ef-gdo.c 
${CMAKE_CURRENT_SOURCE_DIR}/padding.c ${CMAKE_CURRENT_SOURCE_DIR}/apdu.c ${CMAKE_CURRENT_SOURCE_DIR}/simpletlv.c gp.c 

${CMAKE_CURRENT_SOURCE_DIR}/pkcs15.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-cert.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-data.c
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-pin.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-prkey.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-pubkey.c
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-skey.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-sec.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-algo.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-cache.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-syn.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-emulator-filter.c


${CMAKE_CURRENT_SOURCE_DIR}/muscle.c ${CMAKE_CURRENT_SOURCE_DIR}/muscle-filesystem.c 

${CMAKE_CURRENT_SOURCE_DIR}/ctbcs.c ${CMAKE_CURRENT_SOURCE_DIR}/reader-ctapi.c ${CMAKE_CURRENT_SOURCE_DIR}/reader-pcsc.c
${CMAKE_CURRENT_SOURCE_DIR}/reader-openct.c ${CMAKE_CURRENT_SOURCE_DIR}/reader-tr03119.c 

${CMAKE_CURRENT_SOURCE_DIR}/card-setcos.c ${CMAKE_CURRENT_SOURCE_DIR}/card-flex.c 
${CMAKE_CURRENT_SOURCE_DIR}/card-cardos.c ${CMAKE_CURRENT_SOURCE_DIR}/card-cardos-common.c 
${CMAKE_CURRENT_SOURCE_DIR}/card-tcos.c ${CMAKE_CURRENT_SOURCE_DIR}/card-default.c 
${CMAKE_CURRENT_SOURCE_DIR}/card-mcrd.c ${CMAKE_CURRENT_SOURCE_DIR}/card-starcos.c 
${CMAKE_CURRENT_SOURCE_DIR}/card-openpgp.c 
${CMAKE_CURRENT_SOURCE_DIR}/card-oberthur.c ${CMAKE_CURRENT_SOURCE_DIR}/card-belpic.c
${CMAKE_CURRENT_SOURCE_DIR}/card-atrust-acos.c 
${CMAKE_CURRENT_SOURCE_DIR}/card-entersafe.c ${CMAKE_CURRENT_SOURCE_DIR}/card-epass2003.c 
${CMAKE_CURRENT_SOURCE_DIR}/card-coolkey.c 
${CMAKE_CURRENT_SOURCE_DIR}/card-cac.c ${CMAKE_CURRENT_SOURCE_DIR}/card-cac1.c 
${CMAKE_CURRENT_SOURCE_DIR}/card-cac-common.c 
${CMAKE_CURRENT_SOURCE_DIR}/card-piv.c ${CMAKE_CURRENT_SOURCE_DIR}/card-muscle.c 
${CMAKE_CURRENT_SOURCE_DIR}/card-asepcos.c ${CMAKE_CURRENT_SOURCE_DIR}/card-gemsafeV1.c ${CMAKE_CURRENT_SOURCE_DIR}/card-rutoken.c 
${CMAKE_CURRENT_SOURCE_DIR}/card-rtecp.c ${CMAKE_CURRENT_SOURCE_DIR}/card-myeid.c 
${CMAKE_CURRENT_SOURCE_DIR}/card-itacns.c ${CMAKE_CURRENT_SOURCE_DIR}/card-authentic.c 
${CMAKE_CURRENT_SOURCE_DIR}/card-iasecc.c ${CMAKE_CURRENT_SOURCE_DIR}/iasecc-sdo.c ${CMAKE_CURRENT_SOURCE_DIR}/iasecc-sm.c ${CMAKE_CURRENT_SOURCE_DIR}/cwa-dnie.c 
${CMAKE_CURRENT_SOURCE_DIR}/cwa14890.c 
${CMAKE_CURRENT_SOURCE_DIR}/card-sc-hsm.c ${CMAKE_CURRENT_SOURCE_DIR}/card-dnie.c ${CMAKE_CURRENT_SOURCE_DIR}/card-isoApplet.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-coolkey.c 
${CMAKE_CURRENT_SOURCE_DIR}/card-masktech.c ${CMAKE_CURRENT_SOURCE_DIR}/card-gids.c ${CMAKE_CURRENT_SOURCE_DIR}/card-jpki.c 
${CMAKE_CURRENT_SOURCE_DIR}/card-npa.c ${CMAKE_CURRENT_SOURCE_DIR}/card-esteid2018.c ${CMAKE_CURRENT_SOURCE_DIR}/card-idprime.c 
${CMAKE_CURRENT_SOURCE_DIR}/card-edo.c ${CMAKE_CURRENT_SOURCE_DIR}/card-nqApplet.c ${CMAKE_CURRENT_SOURCE_DIR}/card-skeid.c 
${CMAKE_CURRENT_SOURCE_DIR}/card-eoi.c ${CMAKE_CURRENT_SOURCE_DIR}/card-dtrust.c 

${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-openpgp.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-starcert.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-cardos.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-tcos.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-actalis.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-atrust-acos.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-tccardos.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-piv.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-cac.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-esinit.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-pteid.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-din-66291.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-oberthur.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-itacns.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-gemsafeV1.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-sc-hsm.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-dnie.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-gids.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-iasecc.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-jpki.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-esteid2018.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-idprime.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-nqApplet.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-starcos-esign.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-skeid.c 
${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-eoi.c ${CMAKE_CURRENT_SOURCE_DIR}/pkcs15-dtrust.c 
${CMAKE_CURRENT_SOURCE_DIR}/compression.c ${CMAKE_CURRENT_SOURCE_DIR}/sm.c ${CMAKE_CURRENT_SOURCE_DIR}/aux-data.c 
#$(CMAKE_SOURCE_DIR)/win32versioninfo.res
)

set(Dependencies $(CMAKE_BINARY_DIR)/src/scconf/scconf.lib 
$(CMAKE_BINARY_DIR)/src/common/common.lib 
$(CMAKE_BINARY_DIR)/src/common/libscdl.lib 
$(CMAKE_BINARY_DIR)/src/ui/strings.lib 
$(CMAKE_BINARY_DIR)/src/ui/notify.lib 
$(CMAKE_BINARY_DIR)/src/sm/libsmiso.lib 
$(CMAKE_BINARY_DIR)/src/sm/libsmeac.lib 
$(CMAKE_BINARY_DIR)/src/pkcs15init/pkcs15init.lib
gdi32.lib Comctl32.lib Shell32.lib user32.lib advapi32.lib ws2_32.lib shlwapi.lib
)

add_library(${TARGET_NAME} SHARED ${OpenSC_SOURCES} ${OpenSC_HEADERS})

target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/common)
target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/libopensc)
target_include_directories(${TARGET_NAME} PUBLIC ${CMAKE_SOURCE_DIR}/src/scconf)

set_target_properties(${TARGET_NAME} PROPERTIES
    OUTPUT_NAME ${TARGET_NAME}
    ARCHIVE_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/lib
    RUNTIME_OUTPUT_DIRECTORY ${CMAKE_BINARY_DIR}/bin
)

add_library(${TARGET_NAME}_a STATIC ${OpenSC_SOURCES} ${OpenSC_HEADERS})

target_include_directories(${TARGET_NAME}_a PUBLIC ${CMAKE_SOURCE_DIR}/src/common)

target_link_options(${TARGET_NAME} PRIVATE "/DELAYLOAD:bcrypt.dll")

# Generate the .def file
set(EXPORTS_FILE ${CMAKE_CURRENT_SOURCE_DIR}/libopensc.exports)
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
    COMMAND if EXIST ${CMAKE_CURRENT_SOURCE_DIR}/src/libopensc/opensc.dll.manifest mt -manifest ${CMAKE_CURRENT_SOURCE_DIR}/src/libopensc/opensc.dll.manifest -outputresource:${TARGET_NAME};
    COMMENT "Embedding manifest file into DLL"
)
