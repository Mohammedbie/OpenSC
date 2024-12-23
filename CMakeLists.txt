cmake_minimum_required(VERSION 3.20)

project(OpenSC LANGUAGES CXX C)

# Set the output target name
set(TARGET_NAME OpenSC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src/common)
add_subdirectory(src/libopensc)
add_subdirectory(src/minidriver)
add_subdirectory(src/pkcs11)
add_subdirectory(src/pkcs15init)
add_subdirectory(src/scconf)
add_subdirectory(src/sm)
add_subdirectory(src/ui)
