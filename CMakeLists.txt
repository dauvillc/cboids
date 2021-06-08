cmake_minimum_required(VERSION 3.10)

# set the project name
project(Boids VERSION 1.00)

# add the executable
add_executable(Boids main.cpp
    include/sdl_methods.h
    include/drawer.h
    include/boid.h
    include/tests.h
    include/mathtools.h
    src/sdl_methods.cpp
    src/drawer.cpp
    src/boid.cpp
    src/tests.cpp
    src/mathtools.cpp
)

target_include_directories(Boids PRIVATE include)

find_package(SDL2 REQUIRED)
target_include_directories(Boids PRIVATE ${SDL2_INCLUDE_DIRS})
target_link_libraries(Boids ${SDL2_LIBRARIES})