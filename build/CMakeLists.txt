cmake_minimum_required(VERSION 3.14.5)

# Compile according to C++17 standard
set(CMAKE_CXX_STANDARD 17)

project(Goon)

file(GLOB SRC src/*.cpp external/*.cpp)

include_directories(include/)

find_package(SFML 2.5 COMPONENTS system window graphics audio REQUIRED)

add_executable(${PROJECT_NAME} ${SRC})

target_link_libraries(${PROJECT_NAME} sfml-system sfml-window sfml-graphics sfml-audio)