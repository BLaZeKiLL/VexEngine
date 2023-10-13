find_package(glfw3 CONFIG REQUIRED)
find_package(glad CONFIG REQUIRED)
find_package(glm CONFIG REQUIRED)
find_package(spdlog CONFIG REQUIRED)
find_package(assimp CONFIG REQUIRED)
find_package(imgui CONFIG REQUIRED)

file(GLOB_RECURSE VEX_VENDOR_SOURCES "${CMAKE_CURRENT_SOURCE_DIR}/src/*.cpp")

add_library(VEX_VENDOR ${VEX_VENDOR_SOURCES})

if (WIN32)
    if (CMAKE_BUILD_TYPE MATCHES "Debug")
        target_compile_options(VEX_VENDOR PUBLIC /MTd)
    else()
        target_compile_options(VEX_VENDOR PUBLIC /MT)
    endif()
endif ()

target_include_directories(VEX_VENDOR PUBLIC "${CMAKE_CURRENT_SOURCE_DIR}/include")

target_include_directories(VEX_VENDOR INTERFACE "${CMAKE_CURRENT_SOURCE_DIR}/public")

target_link_libraries(VEX_VENDOR PUBLIC glfw glad::glad glm::glm spdlog::spdlog_header_only assimp::assimp imgui::imgui)
