cmake_minimum_required(VERSION 3.09)
project(Huffman)

set(CMAKE_CXX_STANDARD 14)

find_package(OpenCV REQUIRED)

include_directories(.)

add_executable(Huffman
        Heap.cpp
        Heap.hpp
        HeapNode.cpp
        HeapNode.hpp
        main.cpp
        Util.cpp
        Util.h Huffman.hpp Huffman.cpp)

target_link_libraries(Huffman ${OpenCV_LIBS})
