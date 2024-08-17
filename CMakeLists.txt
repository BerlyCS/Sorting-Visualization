cmake_minimum_required(VERSION 3.10)

project(SortingVisual)

set(CMAKE_CXX_STANDARD 17)
set(CMAKE_CXX_STANDARD_REQUIRED True)

find_package(Curses REQUIRED)
include_directories(${CURSES_INCLUDE_DIR})

find_package(SDL2 REQUIRED)
include_directories(${SDL2_INCLUDE_DIRS})

set(SOURCES
    src/main.cpp
    src/sort_array.cpp
    src/algo.cpp
)

add_executable(sort ${SOURCES})

target_link_libraries(sort ${CURSES_LIBRARIES} ${SDL2_LIBRARIES})
