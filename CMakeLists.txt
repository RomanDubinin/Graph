cmake_minimum_required(VERSION 3.3)
project(Graph)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

find_package(Boost
        1.44.0                      # Minimum or EXACT version e.g. 1.36.0
        REQUIRED                    # Fail with error if Boost is not found
        # [COMPONENTS <libs>...]    # Boost libraries by their canonical name
)

set(SOURCE_FILES
    GraphCount/GraphCount/Graph.cpp
    GraphCount/GraphCount/Main.cpp)

add_executable(Graph ${SOURCE_FILES})