cmake_minimum_required(VERSION 3.00)
project(aurio VERSION 0.0.1 LANGUAGES C)

set(CMAKE_C_STANDARD 99)

enable_testing()
add_subdirectory(src/)
add_subdirectory(cmocka/)
add_subdirectory(tests/)
