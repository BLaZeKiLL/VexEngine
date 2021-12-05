file(GLOB_RECURSE MODEL_VIEWER_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(ModelViewer ${MODEL_VIEWER_SOURCES})

if (CMAKE_BUILD_TYPE MATCHES "Debug")
    target_compile_options(ModelViewer PUBLIC /MTd)
else()
    target_compile_options(ModelViewer PUBLIC /MT)
endif()

target_include_directories(ModelViewer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(ModelViewer PRIVATE VEX_RUNTIME)
