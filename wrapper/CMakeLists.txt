cmake_minimum_required(VERSION 3.1)
project(VideoStreamer.NET)

set(CMAKE_WARNINGE_MAKEFILE OFF)
set_property(GLOBAL PROPERTY USE_FOLDERS ON)
set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++14  /clr")

include_directories(${CMAKE_CURRENT_SOURCE_DIR}/../native/VideoStreamer)
link_directories(		${CMAKE_CURRENT_SOURCE_DIR}/../cots/vlc/lib)

file(GLOB SOURCES "*.c*")
file(GLOB HEADERS "*.h*")

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_WINSOCK_DEPRECATED_NO_WARNINGS)
endif()

add_library(${PROJECT_NAME} SHARED ${HEADERS} ${SOURCES})

set_target_properties(${PROJECT_NAME} PROPERTIES COMPILE_FLAGS "/clr")
string(REPLACE "/EHsc" "/EHa" CMAKE_CXX_FLAGS ${CMAKE_CXX_FLAGS})
string(REPLACE "/RTC1" "" CMAKE_CXX_FLAGS_DEBUG ${CMAKE_CXX_FLAGS_DEBUG})
target_link_libraries(${PROJECT_NAME} libvlccore.lib libvlc.lib)
target_link_libraries(${PROJECT_NAME} VideoStreamer)