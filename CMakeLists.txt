cmake_minimum_required(VERSION 2.8)

project(testas)

SET(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")
SET(SOURCE_FILES
    src/main.cpp
    src/game.cpp
    src/animator.cpp


    )


add_executable(animator ${SOURCE_FILES})

include_directories( include )
target_link_libraries(animator sfml-graphics sfml-window sfml-system)
