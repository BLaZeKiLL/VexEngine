file(GLOB_RECURSE VEX_RUNTIME_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(VEX_RUNTIME ${VEX_RUNTIME_SOURCES})

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    target_compile_options(VEX_RUNTIME PUBLIC /MTd)
else()
    target_compile_options(VEX_RUNTIME PUBLIC /MT)
endif()

target_include_directories(VEX_RUNTIME PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_include_directories(VEX_RUNTIME INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/public")

target_link_libraries(VEX_RUNTIME PUBLIC VEX_CORE)
