cmake_minimum_required(VERSION 3.5)
project(Trie)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp Trie.cpp Trie.h)
add_executable(Trie ${SOURCE_FILES})