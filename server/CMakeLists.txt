cmake_minimum_required(VERSION 3.20)
set(CMAKE_C_STANDARD 99)

project(server-lilsaferoom)

add_executable(${PROJECT_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/server/src/main.c)

include_directories(
        include
)