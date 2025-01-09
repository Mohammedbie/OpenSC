# Make to CMake Conversion

To convert projects from Make build system to CMake build system to be able to debug on Windows, you need to do the following:

1. [Understand Makefile.mak files structure and instructions.](./Makefile.md)
2. [Understand CMakeLists.txt files structure and +instructions.](./CMakeLists.md)
3. [Start interpreting the Makefile.mak files into CMakeLists.txt files](#interpreting-the-makefilemak-files-into-cmakeliststxt-files).

## Interpreting the Makefile.Mak files into CMakeLists.txt files

### How to achieve /DELAYLOAD:bcrypt.dll in CMakeLists.txt file?

To achieve /DELAYLOAD:bcrypt.dll in a CMakeLists.txt file, you need to set the appropriate linker flags. This is done by specifying the /DELAYLOAD option for the linker when building your target.

#### Here’s how you can configure this in CMake:

Steps to Add /DELAYLOAD for bcrypt.dll

1. Add the Target Link Option
   Use target_link_options() to pass the /DELAYLOAD option to the linker for the desired target.

2. Link Delayimp.lib
   The /DELAYLOAD option requires the Delayimp.lib library, which should be linked to the target.

3. Specify bcrypt.dll as the Delayloaded Library
   Use the /DELAYLOAD:bcrypt.dll linker flag.

#### CMakeLists.txt Example

Here is a sample configuration for adding /DELAYLOAD:bcrypt.dll to a target:

```cmake
cmake_minimum_required(VERSION 3.15)

# Define your project
project(MyApp LANGUAGES CXX)

# Add the executable or library target
add_executable(MyApp main.cpp)

# Link delayimp.lib (required for /DELAYLOAD)
target_link_libraries(MyApp PRIVATE delayimp)

# Add the /DELAYLOAD:bcrypt.dll linker flag
target_link_options(MyApp PRIVATE "/DELAYLOAD:bcrypt.dll")
```

#### Explanation

**1. target_link_libraries(MyApp PRIVATE delayimp):** This links the Delayimp.lib library, which is necessary for delayed loading to work on Windows.

**2. target_link_options(MyApp PRIVATE "/DELAYLOAD:bcrypt.dll"):** This instructs the linker to delay-load the bcrypt.dll library.

> #### Additional Notes
>
> Ensure you are building on Windows since **/DELAYLOAD** is a Microsoft-specific linker flag.
> The delayimp.lib is part of the Microsoft Visual Studio toolchain and is usually available in the default library paths.

### What is this option "/def:$\*.def"?

> The option **/def:\<filename>** is a linker option used in Microsoft's linker (link.exe). It specifies a module-definition file (commonly known as a .def file) that provides the linker with instructions about how to create a dynamic-link library (DLL) or executable.

#### Purpose of /def Option

The **/def:\<filename>** option allows you to:

**1.Define Exported Symbols:** Specify which functions or variables should be exported from a DLL.

**2.Control Ordinals:** Define ordinals for exported functions, which are useful for versioning or optimizing runtime performance.

**3.Specify Library Information:** Provide details such as the library name, dependencies, and module attributes.

#### Key Elements in a .def File

A **.def** file typically contains:

**1. LIBRARY:** Defines the name of the DLL.

**2. EXPORTS:** Lists the symbols (functions or
variables) to be exported.

**3. DESCRIPTION:** An optional description of the library.

**4. SECTIONS:** Optional directives for section attributes.

#### Example .def file:

```plaintext
LIBRARY MyLibrary
EXPORTS
MyFunction1
MyFunction2 @2 ; Explicitly assigns ordinal 2
MyVariable DATA ; Specifies that MyVariable is a data export
```

#### When to Use /def

- **DLL Creation:** When exporting specific functions or variables.
- **Custom Ordinals:** To control or preserve ordinal numbers for exported symbols.
- **Simplified Export Management:** Instead of annotating each export in code (e.g., with \_\_declspec(dllexport)), you manage them in the .def file.

#### What Does /def:$\*.def Mean?

> This is a pattern often used in build systems to dynamically refer to a .def file associated with a source file or target:

**$\\\***: Represents the base name of a file (e.g., without the extension).
.def: Appends the .def extension to the base name.
For example:

If the target name is MyLibrary, **$\\\***.def would resolve to MyLibrary.def.
The linker would use this .def file for the current target during the build process.

#### Usage in CMake

In CMake, you can specify a .def file using the target_link_options() or set_target_properties() command.

#### Example:

```cmake

# Add a library target

add_library(MyLibrary SHARED MyLibrary.cpp)

# Specify the .def file for the linker

set_target_properties(MyLibrary PROPERTIES LINK_FLAGS "/def:MyLibrary.def")
```

**Or:**

```cmake

# Use target_link_options

target_link_options(MyLibrary PRIVATE "/def:MyLibrary.def")
```

#### Advantages of Using .def Files

**1. Simplifies Code:** Reduces the need to use \_\_declspec(dllexport) for every exported function.
**2. Backward Compatibility:** Maintains consistent ordinal numbers for exports, essential for versioned DLLs.
**3. Custom Control:** Allows for fine-grained control over exports.

## Summary

> You can use AI like Chatgpt to ask for specific Makefiles expression meaning then try to convert it to what it looks like in CMakeLists files by using Chatgpt as a guide.
