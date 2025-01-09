# What is a CMakeLists?

> The `CMakeLists.txt` file is a configuration file used by `CMake`, a **cross-platform build system**. This file contains **commands** and **settings** to specify how your project should be built, including information about **source files**, **libraries**, **build options**, **dependencies**, and **installation details**.

## Key Features of CMakeLists.txt

**1. Cross-Platform Build Support:** It generates platform-specific build scripts, like Makefiles (Linux), Visual Studio project files (Windows), or Xcode project files (macOS).

**2. Target-Based Approach:** Modern CMake focuses on defining "targets" (executables, libraries, etc.) and specifying their properties like source files, include directories, and linked libraries.

## Structure and Commands in CMakeLists.txt

Here are the most commonly used commands and concepts in a CMakeLists.txt file:

**1. Setting the Minimum Required Version**

```cmake
cmake_minimum_required(VERSION <version>)
```

This ensures the CMake version meets the required functionality. Example:

```cmake
cmake_minimum_required(VERSION 3.20)
```

**2. Project Definition**

```cmake
project(<project_name> [LANGUAGES <languages>])
```

Defines the name and supported languages of the project. Example:

```cmake
project(MyApp LANGUAGES CXX C)
```

**3. Specifying the C++ Standard**

```cmake
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_CXX_EXTENSIONS OFF)
```

Defines the C++ standard and enforces compliance.

**4. Adding Source Files**

- To add an executable:

```cmake
add_executable(<target> <source_files>)
```

- To add a library:

```cmake
add_library(<target> [STATIC | SHARED | MODULE] <source_files>)
```

Example:

```cmake
add_executable(MyApp main.cpp app.cpp)
add_library(MyLibrary STATIC lib.cpp lib.h)
```

**5. Linking Libraries**

```cmake
target_link_libraries(<target> <PRIVATE | PUBLIC | INTERFACE> <libraries>)
```

Defines which libraries a target depends on.

Example:

```cmake
target_link_libraries(MyApp PRIVATE MyLibrary)
```

**6. Include Directories**

```cmake
target_include_directories(<target> <PRIVATE | PUBLIC | INTERFACE> <directories>)
```

Specifies include paths for a target.

Example:

```cmake
target_include_directories(MyLibrary PUBLIC ${CMAKE_SOURCE_DIR}/include)
```

**7. Setting Build Options**

```cmake
option(<option> "Description" <default_value>)
```

Defines configurable options for your project.

Example:

```cmake
option(BUILD_TESTS "Build the tests" ON)
```

**8. Adding Subdirectories**

```cmake
add_subdirectory(<directory>)
```

Used to include other CMakeLists.txt files from subprojects.

Example:

```cmake
add_subdirectory(src)
add_subdirectory(tests)
```

**9. Installation Rules**

```cmake
install(TARGETS <targets> [EXPORT <export_name>] [DESTINATION <path>])
```

Defines how files should be installed on the system.

Example:

```cmake
install(TARGETS MyApp DESTINATION bin)
```

**10. Finding Packages**

```cmake
find_package(<package> [REQUIRED])
```

Finds external dependencies.

Example:

```cmake
find_package(Qt5 REQUIRED COMPONENTS Widgets)
target_link_libraries(MyApp PRIVATE Qt5::Widgets)
```

## Modern CMake Practices

**1. Target-Centric Commands:**

Avoid global commands like include_directories() and link_libraries().
Use target-specific commands like target_include_directories().

**2. Variables:**

Use **CACHE** variables for configuration options.
Avoid hardcoding paths; use CMake variables like **\${CMAKE_SOURCE_DIR}** and **${CMAKE_BINARY_DIR}**.

**3. Modularity:**

Split large projects into multiple CMakeLists.txt files.
Use add_subdirectory() for hierarchical structure.

## Example CMakeLists.txt

Below is an example of a basic CMakeLists.txt file for a C++ project using Qt and a custom library:

```cmake
cmake_minimum_required(VERSION 3.20)

# Project name and languages

project(MyQtApp LANGUAGES CXX)

# Set C++ standard

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# Find Qt libraries

find_package(Qt5 REQUIRED COMPONENTS Widgets)

# Add source files

add_executable(MyApp main.cpp app.cpp)

# Add a custom library

add_library(MyLibrary STATIC lib.cpp lib.h)

# Include directories

target_include_directories(MyLibrary PUBLIC ${CMAKE_SOURCE_DIR}/include)

# Link libraries

target_link_libraries(MyApp PRIVATE MyLibrary Qt5::Widgets)

# Installation

install(TARGETS MyApp DESTINATION bin)
install(FILES app.ui DESTINATION share/MyQtApp)
```

## Advanced Topics

**1. Custom Build Commands**

- Use add_custom_command() to define custom actions during build.
- Use add_custom_target() for custom targets.

**2. Generators**

- Use generator expressions like $<CONFIG> for configuration-specific options.

**3. Exporting and Importing Targets**

- Use install(EXPORT) and export() to create reusable target definitions.

## Debugging CMake

- Use message() to print debug information.
- Run CMake with --trace or --debug-output for detailed logs.
