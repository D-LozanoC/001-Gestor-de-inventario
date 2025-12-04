cmake_minimum_required(VERSION 3.16)

project(001GestorInventario)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED True)

include_directories(include)

file(GLOB SOURCES 
    "src/*.cpp"
    "main.cpp"
)

add_executable(001GestorInventario ${SOURCES})
