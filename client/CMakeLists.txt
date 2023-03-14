cmake_minimum_required(VERSION 3.20)
set(CMAKE_C_STANDARD 99)

project(client-lilsaferoom)

add_executable(${PROJECT_NAME}
        ${CMAKE_CURRENT_SOURCE_DIR}/client/src/main.c)


include_directories(
        include
)