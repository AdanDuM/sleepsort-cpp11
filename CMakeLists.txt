cmake_minimum_required(VERSION 2.8)
project(sleepsort-cpp11)

# -Ofast improves performance deeply
set(CMAKE_CXX_FLAGS "-Ofast -Wall -Werror -Wpedantic")
find_package(Threads REQUIRED)

add_executable(sleepsort sleepsort.cpp)
set_property(TARGET sleepsort PROPERTY CXX_STANDARD 11)
target_link_libraries(sleepsort ${CMAKE_THREAD_LIBS_INIT})
