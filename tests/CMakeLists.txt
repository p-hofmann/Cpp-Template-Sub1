cmake_minimum_required(VERSION 3.5)
set(CMAKE_CXX_STANDARD 11)

###############
# Unittests
###############

# Name the test project
set(TEST_PROJECT_NAME UnitTest_CppTemplateSub1)
project(${TEST_PROJECT_NAME} VERSION 0.0.1 LANGUAGES CXX)

# Find out if the current architecture is 32 or 64 bit and
# This will add the equal of '#define BUILD_ARCH_64BIT' to each file in case of a 64bit architecture
if (CMAKE_SIZEOF_VOID_P EQUAL 8)
    add_definitions(-DBUILD_ARCH_64BIT)
endif ()

#set location for include and src folder
set(SRC_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../src)
set(INCLUDE_LOCATION ${CMAKE_CURRENT_SOURCE_DIR}/../include)

# Project will be made into an executable
add_executable(${TEST_PROJECT_NAME}
    test_cpptemplatesub1.cpp
#    ${PLATFORM_DEPENENT_FILES}
    ${SRC_LOCATION}/cpptemplatesub1.cpp ${INCLUDE_LOCATION}/cpptemplatesub1.h
    )

# add submodule library
target_link_libraries(${TEST_PROJECT_NAME} CppTemplateSub1Sub CppTemplateSub1)

# Make sure that Catch2 exists
add_dependencies(${TEST_PROJECT_NAME} catch2_project)

# get catch2 src directory
ExternalProject_Get_Property(catch2_project SOURCE_DIR)

# This will specify for this project only, /src and /include as the folders to look into for files
target_include_directories(${TEST_PROJECT_NAME}
    PUBLIC
        $<BUILD_INTERFACE:${INCLUDE_LOCATION}>
        $<INSTALL_INTERFACE:${INCLUDE_LOCATION}>
        ${INCLUDE_LOCATION}
    PRIVATE
        ${SRC_LOCATION}
        ${SOURCE_DIR}/single_include/catch2
    )
# Note, that the catch2 library location was added

# Adding test for 'ctest'
add_test(
    NAME ${TEST_PROJECT_NAME}
    COMMAND ${TEST_PROJECT_NAME})
