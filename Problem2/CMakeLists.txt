cmake_minimum_required(VERSION 3.24)
project(problem2)

set(CMAKE_CXX_STANDARD 20)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/build")
add_executable(problem2 main.cpp Song.cpp SongCollection.cpp)