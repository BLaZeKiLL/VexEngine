file(GLOB_RECURSE VEX_CORE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(VEX_CORE ${VEX_CORE_SOURCES})

if (WIN32)
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
        target_compile_options(VEX_CORE PUBLIC /MTd)
    else()
        target_compile_options(VEX_CORE PUBLIC /MT)
    endif()
endif ()

target_include_directories(VEX_CORE PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_include_directories(VEX_CORE INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/public")

target_link_libraries(VEX_CORE PUBLIC VEX_VENDOR)

if (WIN32)
    target_compile_definitions(VEX_CORE PUBLIC VEX_WINDOWS)
endif()

if (UNIX)
    target_compile_definitions(VEX_CORE PUBLIC VEX_OSX)
endif()
