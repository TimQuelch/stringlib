cmake_minimum_required(VERSION 3.10)
project(stringlib VERSION 0.1.0)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_INCLUDE_CURRENT_DIR ON)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -march=native -O3 -pipe -g")
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -Wall -Werror -Wextra -Wpedantic")

include_directories(include)

enable_testing()

add_subdirectory(src)
add_subdirectory(docs)
add_subdirectory(test)
