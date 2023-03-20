file(GLOB_RECURSE MODEL_VIEWER_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_executable(ModelViewer ${MODEL_VIEWER_SOURCES})

add_custom_command(
	TARGET ModelViewer POST_BUILD COMMAND ${CMAKE_COMMAND} -E copy_directory
	"${CMAKE_CURRENT_SOURCE_DIR}/assets" "$<TARGET_FILE_DIR:ModelViewer>/assets"
)

if (WIN32)
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
        target_compile_options(ModelViewer PUBLIC /MTd)
    else()
        target_compile_options(ModelViewer PUBLIC /MT)
    endif()
endif ()

target_include_directories(ModelViewer PRIVATE "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_link_libraries(ModelViewer PRIVATE VEX_RUNTIME)
