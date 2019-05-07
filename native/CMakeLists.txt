cmake_minimum_required(VERSION 3.1)
project(VideoStreamerSample)

set(VideoStreamer ${CMAKE_CURRENT_SOURCE_DIR}/VideoStreamer)
add_subdirectory(${VideoStreamer})

include_directories(${VideoStreamer})
link_directories(		${CMAKE_CURRENT_SOURCE_DIR}/../cots/vlc/lib)

file(GLOB MAIN "*.c*")

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_WINSOCK_DEPRECATED_NO_WARNINGS)
endif()

add_executable(${PROJECT_NAME} ${MAIN})
target_link_libraries(${PROJECT_NAME} libvlccore.lib libvlc.lib)
target_link_libraries(${PROJECT_NAME} VideoStreamer)