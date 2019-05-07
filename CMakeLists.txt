cmake_minimum_required(VERSION 3.1)
project(VideoStreamer)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14")

set(NATIVE ${CMAKE_CURRENT_SOURCE_DIR}/native)
#set(WRAPPER ${CMAKE_CURRENT_SOURCE_DIR}/wrapper)

add_subdirectory(${NATIVE})
#add_subdirectory(${WRAPPER})