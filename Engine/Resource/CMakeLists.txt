file(GLOB_RECURSE VEX_RESOURCE_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(VEX_RESOURCE ${VEX_RESOURCE_SOURCES})

if (WIN32)
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
        target_compile_options(ModelViewer PUBLIC /MTd)
    else()
        target_compile_options(ModelViewer PUBLIC /MT)
    endif()
endif ()

target_include_directories(VEX_RESOURCE PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_include_directories(VEX_RESOURCE INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/public")

target_link_libraries(VEX_RESOURCE PUBLIC VEX_CORE)
