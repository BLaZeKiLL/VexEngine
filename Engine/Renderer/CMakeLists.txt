file(GLOB_RECURSE VEX_RENDERER_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(VEX_RENDERER ${VEX_RENDERER_SOURCES})

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    target_compile_options(VEX_RENDERER PUBLIC /MTd)
else()
    target_compile_options(VEX_RENDERER PUBLIC /MT)
endif()

target_include_directories(VEX_RENDERER PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_include_directories(VEX_RENDERER INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/public")

target_link_libraries(VEX_RENDERER PUBLIC VEX_CORE VEX_RESOURCE)
