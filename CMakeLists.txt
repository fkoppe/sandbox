cmake_minimum_required(VERSION 3.22 FATAL_ERROR)
project(sandbox LANGUAGES C)

set(CMAKE_C_STANDARD 99)
set(CMAKE_C_STANDARD_REQUIRED ON)

set(CMAKE_CODELITE_USE_TARGETS ON)

add_executable(sandbox main.c)

enable_testing()

target_link_libraries(
    sandbox
    PUBLIC
    darkstar
)

add_subdirectory(library)
