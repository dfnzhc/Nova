cmake_minimum_required(VERSION 3.23)

project(Framework CXX)

add_executable(01_framework main.cpp)

target_link_libraries(01_framework
        PRIVATE Nova)

set_target_properties(01_framework PROPERTIES
        CXX_STANDARD 23
        RUNTIME_OUTPUT_DIRECTORY ${NOVA_RUNTIME_OUTPUT_DIR}
        LIBRARY_OUTPUT_DIRECTORY ${NOVA_LIBRARY_OUTPUT_DIR}
)

set_property(TARGET 01_framework PROPERTY FOLDER "Samples")