cmake_minimum_required(VERSION 3.20)
set(CMAKE_C_STANDARD 99)

project(lilsaferoom)

include(${CMAKE_CURRENT_SOURCE_DIR}/server/CMakeLists.txt)
include(${CMAKE_CURRENT_SOURCE_DIR}/client/CMakeLists.txt)