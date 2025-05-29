cmake_minimum_required(VERSION 3.10)

# Use clang++ explicitly
set(CMAKE_C_COMPILER "/usr/bin/clang")
set(CMAKE_CXX_COMPILER "/usr/bin/clang++")

project(flappy)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_EXPORT_COMPILE_COMMANDS ON)

# GLAD
add_library(glad src/glad.c)
target_include_directories(glad PUBLIC ${CMAKE_SOURCE_DIR}/include)

# GLFW using pkg-config
find_package(PkgConfig REQUIRED)
pkg_check_modules(GLFW REQUIRED glfw3)

#glw
find_package(glm CONFIG REQUIRED)

# OpenGL (macOS)
find_package(OpenGL REQUIRED)

# Executable
file(GLOB_RECURSE SRC_FILES CONFIGURE_DEPENDS src/*.cpp)

add_executable(flappy ${SRC_FILES} main.cpp)

target_include_directories(flappy PRIVATE
    ${GLFW_INCLUDE_DIRS}
    ${CMAKE_SOURCE_DIR}/include
)

target_link_directories(flappy PRIVATE
    ${GLFW_LIBRARY_DIRS}
)

target_link_libraries(flappy
    glad
    ${GLFW_LIBRARIES}
    ${OPENGL_LIBRARIES}
    glm::glm-header-only
)
