cmake_minimum_required(VERSION 3.26)
project(saper)

set(CMAKE_CXX_STANDARD 17)

add_compile_options(-Wall -Wextra)
add_compile_options(-pedantic)
add_compile_options(-Werror=return-type)
add_compile_options(-Werror=parentheses)
add_compile_options(-Werror=vla)
add_compile_options(-Werror=array-bounds)
add_compile_options ( -Wcast-qual )
add_compile_options ( -Wmaybe-uninitialized )

add_executable(saper main.cpp
        Array2D.h
        MinesweeperBoard.h
        MinesweeperBoard.cpp)
