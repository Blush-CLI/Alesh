cmake_minimum_required(VERSION 3.20)

project(Alesh)

set(CMAKE_CXX_STANDARD 23)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

add_executable(alesh
    src/lexer/lexer.hpp
    src/lexer/token.hpp
    
    src/lexer/lexer.cpp
    src/main.cpp
)

target_include_directories(alesh PRIVATE
    include
)