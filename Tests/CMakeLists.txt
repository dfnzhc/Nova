cmake_minimum_required(VERSION 3.27)

project(${PROJECT_NAME}Test LANGUAGES CXX)

set(gtest_force_shared_crt ON CACHE BOOL "" FORCE)

find_package(GTest CONFIG REQUIRED)
find_package(benchmark CONFIG REQUIRED)

set(TEST_SOURCES
        Base/BaseTest.cpp
        
        Utils/LoggerTest.cpp
        Utils/TerminalTest.cpp
)

set(${CMAKE_CURRENT_BINARY_DIR})

foreach (FILE ${TEST_SOURCES})
    get_filename_component(FILE_NAME ${FILE} NAME_WE)
    add_executable(${FILE_NAME} ${FILE})
    set_property(TARGET ${FILE_NAME} PROPERTY FOLDER "Tests")

    target_link_libraries(${FILE_NAME}
            PUBLIC GTest::gtest GTest::gtest_main benchmark::benchmark
            PRIVATE Nova)

    set_target_properties(${FILE_NAME} PROPERTIES
            CXX_STANDARD 20
            RUNTIME_OUTPUT_DIRECTORY ${NOVA_RUNTIME_OUTPUT_DIR}
            LIBRARY_OUTPUT_DIRECTORY ${NOVA_LIBRARY_OUTPUT_DIR}
    )
    add_test(NAME "${FILE_NAME}Test"
            COMMAND ${FILE_NAME}
            WORKING_DIRECTORY ${NOVA_RUNTIME_OUTPUT_DIR})
endforeach ()
