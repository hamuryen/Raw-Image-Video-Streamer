cmake_minimum_required(VERSION 3.1)
project(VideoStreamer)

set(CMAKE_AUTOMOC ON)
set(CMAKE_AUTOUIC ON)


include_directories(	${CMAKE_CURRENT_SOURCE_DIR}
						${CMAKE_CURRENT_SOURCE_DIR}/../../cots/vlc/include)
						
link_directories(		${CMAKE_CURRENT_SOURCE_DIR}/../../cots/vlc/lib)

file(GLOB SOURCES "*.c*")
file(GLOB HEADERS "*.h*")

if(MSVC)
    add_definitions(-D_CRT_SECURE_NO_WARNINGS -D_WINSOCK_DEPRECATED_NO_WARNINGS)
endif()

add_library(${PROJECT_NAME} ${SOURCES} ${HEADERS})
target_link_libraries(${PROJECT_NAME} libvlccore.lib libvlc.lib)