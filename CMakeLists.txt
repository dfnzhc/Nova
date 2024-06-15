cmake_minimum_required(VERSION 3.27)

list(APPEND CMAKE_MODULE_PATH ${CMAKE_CURRENT_SOURCE_DIR}/CMake)

# --------------------------------------------------------------
# Project Configuration
# --------------------------------------------------------------

project(Nova
        LANGUAGES CXX C
        VERSION 0.0.1)

string(TOLOWER ${PROJECT_NAME} PROJECT_NAME_LOWERCASE)
string(TOUPPER ${PROJECT_NAME} PROJECT_NAME_UPPERCASE)

# Set the C++ standard to C++23
set(CMAKE_CXX_STANDARD 23)
# Specify that this standard is required
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include(CompilerFlags)

set(CMAKE_DISABLE_SOURCE_CHANGES ON)
set(CMAKE_DISABLE_IN_SOURCE_BUILD ON)

set(CMAKE_CXX_FLAGS_RELEASE "${CMAKE_CXX_FLAGS_RELEASE} /MT")
set(CMAKE_CXX_FLAGS_DEBUG "${CMAKE_CXX_FLAGS_DEBUG} /MTd")

set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set_property(GLOBAL PROPERTY PREDEFINED_TARGETS_FOLDER "CMake")

# Platform
if (${CMAKE_SYSTEM_NAME} MATCHES "Windows")
    set(${PROJECT_NAME_UPPERCASE}_PLATFORM "Windows")
    set(${PROJECT_NAME_UPPERCASE}_IN_WINDOWS TRUE)
else ()
    # ...
endif ()

add_compile_options("$<$<C_COMPILER_ID:MSVC>:/utf-8>")
add_compile_options("$<$<CXX_COMPILER_ID:MSVC>:/utf-8>")

# --------------------------------------------------------------
# Global settings
# --------------------------------------------------------------

set(${PROJECT_NAME_UPPERCASE}_PRECOMPILED_HEADERS ON CACHE BOOL "Use precompiled header")
set(${PROJECT_NAME_UPPERCASE}_BUILD_TESTS ON CACHE BOOL "Build test programs")
set(${PROJECT_NAME_UPPERCASE}_BUILD_SAMPLES ON CACHE BOOL "Build Sample programs")


# Directory
include_directories(${CMAKE_CURRENT_SOURCE_DIR}/Source)

set(${PROJECT_NAME_UPPERCASE}_RUNTIME_OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin)
set(${PROJECT_NAME_UPPERCASE}_LIBRARY_OUTPUT_DIR ${CMAKE_BINARY_DIR}/bin)

if (CMAKE_CONFIGURATION_TYPES)
    set(CMAKE_CONFIGURATION_TYPES "Debug;Release;MinSizeRel;RelWithDebInfo" CACHE STRING "" FORCE)
else ()
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY HELPSTRING "Choose the type of build")
    set_property(CACHE CMAKE_BUILD_TYPE PROPERTY STRINGS "Debug;Release;MinSizeRel;RelWithDebInfo")
endif ()

if (CMAKE_CONFIGURATION_TYPES)
    set(${PROJECT_NAME_UPPERCASE}_OUTPUT_DIR ${${PROJECT_NAME_UPPERCASE}_RUNTIME_OUTPUT_DIR}/$<CONFIG>)
else ()
    set(${PROJECT_NAME_UPPERCASE}_OUTPUT_DIR ${${PROJECT_NAME_UPPERCASE}_RUNTIME_OUTPUT_DIR})
endif ()

# --------------------------------------------------------------
# Utils
# --------------------------------------------------------------

# Copy data files to output directory
add_custom_target(copy_data_folder ALL
        COMMAND ${CMAKE_COMMAND} -E copy_directory ${CMAKE_SOURCE_DIR}/Data ${${PROJECT_NAME_UPPERCASE}_OUTPUT_DIR}/Data)
set_target_properties(copy_data_folder PROPERTIES FOLDER "Misc")

# --------------------------------------------------------------
# Includes
# --------------------------------------------------------------
######################################
# Third party libraries
include(cmake/CPM.cmake)
add_subdirectory(ThirdParty)

######################################
# Nova
add_subdirectory(Source/Nova)
add_dependencies(Nova copy_data_folder)
target_include_directories(${PROJECT_NAME} PUBLIC ${CMAKE_CURRENT_SOURCE_DIR})

if (${PROJECT_NAME_UPPERCASE}_BUILD_SAMPLES)
    add_subdirectory(Samples)
endif ()

######################################
# 测试
if (${PROJECT_NAME_UPPERCASE}_BUILD_TESTS)
    enable_testing()
    add_subdirectory(Tests)
endif ()
