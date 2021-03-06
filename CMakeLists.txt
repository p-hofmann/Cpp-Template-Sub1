cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)

# Have all executables in the bin folder, so continuous integratian can easily call them
set(EXECUTABLE_OUTPUT_PATH ${CMAKE_SOURCE_DIR}/bin)
# Have all libraries in the libs folder, all submodules will compile their libraries into there
set(LIBRARY_OUTPUT_PATH ${CMAKE_CURRENT_SOURCE_DIR}/libs)

# Name the project and add a version number
project(CppTemplateSub1 VERSION 0.0.2 LANGUAGES CXX)

# Find out if the current architecture is 32 or 64 bit and
# This will add the equal of '#define BUILD_ARCH_64BIT' to each file in case of a 64bit architecture
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    add_definitions(-DBUILD_ARCH_64BIT)
endif ()

# Make a static library
add_library(CppTemplateSub1
    src/cpptemplatesub1.cpp include/cpptemplatesub1.h
#    ${PLATFORM_DEPENENT_FILES}
    )

# make sure this module knows the header location of the sub module
target_link_libraries(CppTemplateSub1 CppTemplateSub1Sub)

# This will specify for this project only, /src and /include as the folders to look into for files
target_include_directories(CppTemplateSub1
    PUBLIC
    $<BUILD_INTERFACE:${CMAKE_CURRENT_SOURCE_DIR}/include>
    $<INSTALL_INTERFACE:include>
    ${CMAKE_CURRENT_SOURCE_DIR}/include
    PRIVATE
    ${CMAKE_CURRENT_SOURCE_DIR}/src
    )

# add external projects
add_subdirectory(external)

# add submodules
add_subdirectory(include/Cpp-Template-Sub1-Sub)

# Add Unittest
# This is done before submodules, or the catch2 will be cloned to the submodule location
enable_testing()
add_subdirectory(tests)
