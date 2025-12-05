cmake_minimum_required(VERSION 3.16)

project(001GestorInventario)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

file(GLOB SOURCES 
    "${CMAKE_SOURCE_DIR}/src/*.cpp"
    "${CMAKE_SOURCE_DIR}/main.cpp"
)

add_executable(001GestorInventario ${SOURCES})

target_include_directories(001GestorInventario PRIVATE
    "${CMAKE_SOURCE_DIR}/include"
)