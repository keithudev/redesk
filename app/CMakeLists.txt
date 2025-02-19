cmake_minimum_required(VERSION 3.5.0)
project(redeskcli)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY ${CMAKE_CURRENT_BINARY_DIR})
set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

include_directories(src)
file(GLOB SOURCES src/*.cpp)

add_executable(${PROJECT_NAME} ${SOURCES})


# Import SDL
add_library(vendor INTERFACE)
target_link_libraries(vendor INTERFACE SDL3::SDL3)

add_subdirectory(vendor/SDL)
target_link_libraries(${PROJECT_NAME} PRIVATE vendor) 

# Import FFmpeg
target_include_directories(${PROJECT_NAME} PRIVATE vendor/ffmpeg/include)
target_link_directories(${PROJECT_NAME} PRIVATE vendor/ffmpeg/lib)
target_link_libraries(${PROJECT_NAME} PRIVATE avcodec avformat avutil)

add_custom_command(
    TARGET ${PROJECT_NAME} POST_BUILD
    COMMAND ${CMAKE_COMMAND} -E copy_directory
            ${CMAKE_SOURCE_DIR}/vendor/ffmpeg/bin
            ${CMAKE_RUNTIME_OUTPUT_DIRECTORY}
)