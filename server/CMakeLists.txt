cmake_minimum_required(VERSION 3.20)
set(CMAKE_C_STANDARD 99)

project(server-lilsaferoom)

file(GLOB_RECURSE SRC_FILES src/*.c)

add_executable(${PROJECT_NAME}
        ${SRC_FILES}
        )

include_directories(
        include/
)

target_link_libraries(${PROJECT_NAME}
        curses)