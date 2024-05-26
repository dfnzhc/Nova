# TODO: 添加静态库版本
add_library(${PROJECT_NAME} SHARED)

set_compiler_flags(${PROJECT_NAME})

if (${PROJECT_NAME}_PRECOMPILED_HEADERS)
    target_precompile_headers(${PROJECT_NAME} PRIVATE ${PROJECT_NAME}.hpp)
endif ()

set(BASE_FILES
        Base/Base.hpp
        Base/Base.cpp
        Base/Defines.hpp
)

set(UTILS_FILES
        Utils/Logger.hpp Utils/Logger.cpp
        Utils/Terminal.hpp
)

source_group("Base" FILES ${BASE_FILES})
source_group("Math" FILES ${MATH_FILES})
source_group("Memory" FILES ${MEMORY_FILES})
source_group("Utils" FILES ${UTILS_FILES})

target_sources(${PROJECT_NAME}
        PRIVATE
        ${PROJECT_NAME}.hpp
        ${BASE_FILES}
        ${UTILS_FILES}
)

target_compile_features(${PROJECT_NAME}
        PUBLIC cxx_std_20
        PRIVATE cxx_std_20
)

#target_link_libraries(${PROJECT_NAME}
#        #    PRIVATE
#        PUBLIC
#)

target_compile_definitions(${PROJECT_NAME}
        PUBLIC
        $<$<CONFIG:Release>:NDEBUG>
        $<$<CONFIG:Debug>:_DEBUG>
        # Windows
        $<$<PLATFORM_ID:Windows>:NOMINMAX>
        $<$<PLATFORM_ID:Windows>:UNICODE>
        # MSVC C++ 
        $<$<CXX_COMPILER_ID:MSVC>:_USE_MATH_DEFINES>
        $<$<CXX_COMPILER_ID:MSVC>:_SCL_SECURE_NO_WARNINGS>
        $<$<CXX_COMPILER_ID:MSVC>:_CRT_SECURE_NO_WARNINGS>
        $<$<CXX_COMPILER_ID:MSVC>:_ENABLE_EXTENDED_ALIGNED_STORAGE>
        $<$<CXX_COMPILER_ID:MSVC>:_SILENCE_CXX17_CODECVT_HEADER_DEPRECATION_WARNING>
        # Clang.
        $<$<CXX_COMPILER_ID:Clang>:_MSC_EXTENSIONS> # enable MS extensions
        # Custom
        ${PROJECT_NAME_UPPERCASE}_FORCE_USE_ANIS
        PRIVATE
        $<$<CONFIG:Debug>:_ITERATOR_DEBUG_LEVEL=0>
        ${PROJECT_NAME_UPPERCASE}_DLL
)

target_compile_options(${PROJECT_NAME}
        PUBLIC
        # MSVC
        $<$<CXX_COMPILER_ID:MSVC>:/DEBUG>
)

set_target_properties(${PROJECT_NAME} PROPERTIES
        RUNTIME_OUTPUT_DIRECTORY ${${PROJECT_NAME_UPPERCASE}_RUNTIME_OUTPUT_DIR}
        LIBRARY_OUTPUT_DIRECTORY ${${PROJECT_NAME_UPPERCASE}_LIBRARY_OUTPUT_DIR}
)
