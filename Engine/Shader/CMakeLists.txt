file(GLOB_RECURSE VEX_SHADER_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(VEX_SHADER ${VEX_SHADER_SOURCES})

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    target_compile_options(VEX_SHADER PUBLIC /MTd)
else()
    target_compile_options(VEX_SHADER PUBLIC /MT)
endif()

target_include_directories(VEX_SHADER PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_include_directories(VEX_SHADER INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/public")

target_link_libraries(VEX_SHADER PUBLIC VEX_CORE VEX_RESOURCE)
