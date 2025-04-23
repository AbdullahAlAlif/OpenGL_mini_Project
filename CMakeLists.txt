cmake_minimum_required(VERSION 3.10)

# Project name and version
project(ShootingGallery VERSION 1.0)

# Set C++ standard
set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

# Add executable
add_executable(ShootingGallery main.cpp renderer.cpp game.cpp)

# Include GLFW
find_package(glfw3 3.3 REQUIRED)
target_link_libraries(ShootingGallery glfw)

# Include OpenGL
find_package(OpenGL REQUIRED)
target_link_libraries(ShootingGallery OpenGL::GL)

# Include GLM
find_package(glm REQUIRED)
target_include_directories(ShootingGallery PRIVATE ${GLM_INCLUDE_DIRS})
