# CMakeList.txt : Top-level CMake project file, do global configuration and include sub-projects here.
cmake_minimum_required (VERSION 3.8)

# VCPKG Bootstrap
if (WIN32 AND NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.vcpkg/vcpkg.exe")
    execute_process(COMMAND cmd /c "${CMAKE_CURRENT_SOURCE_DIR}/.vcpkg/bootstrap-vcpkg.bat"
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif ()

if (UNIX AND NOT EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/.vcpkg/vcpkg")
    execute_process(COMMAND bash -c "${CMAKE_CURRENT_SOURCE_DIR}/.vcpkg/bootstrap-vcpkg.sh"
            WORKING_DIRECTORY ${CMAKE_CURRENT_SOURCE_DIR})
endif ()

# VCPKG Config
set(CMAKE_TOOLCHAIN_FILE "${CMAKE_CURRENT_SOURCE_DIR}/.vcpkg/scripts/buildsystems/vcpkg.cmake" CACHE STRING "")
set(VCPKG_TARGET_TRIPLET "x64-windows-static" CACHE STRING "")

# Project Config
project ("VexEngine" VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Include sub-projects.

# Engine
add_subdirectory("Engine")

# Games
add_subdirectory("Game/ModelViewer")
