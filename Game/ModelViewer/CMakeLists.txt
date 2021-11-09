add_executable(ModelViewer "src/main.cpp")

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    target_compile_options(ModelViewer PUBLIC /MTd)
else()
    target_compile_options(ModelViewer PUBLIC /MT)
endif()

target_link_libraries(ModelViewer PRIVATE VEX_CORE)
