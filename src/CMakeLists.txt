cmake_minimum_required (VERSION 3.8)

project ("27-1-elf-village")

set(MY_INCLUDE_DIR ${CMAKE_SOURCE_DIR}/include)

add_executable(27-1-elf-village "main.cpp" ${MY_INCLUDE_DIR}/functions.h "functions.cpp" ${MY_INCLUDE_DIR}/branch.h "branch.cpp")

target_include_directories(27-1-elf-village PUBLIC ${CMAKE_SOURCE_DIR}/include)