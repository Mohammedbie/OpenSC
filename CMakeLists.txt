cmake_minimum_required(VERSION 3.20)

project(OpenSC LANGUAGES CXX C)

# Set the output target name
set(TARGET_NAME OpenSC)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_subdirectory(src)
