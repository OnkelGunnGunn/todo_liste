cmake_minimum_required(VERSION 3.20)
project(todo_list)

set(CMAKE_CXX_STANDARD 20)


add_compile_options(
    -Wall
    -Wextra
    -Wpedantic
    -Werror

)

add_executable(todo src/main.cpp src/todo.cpp)
target_include_directories(todo PRIVATE include)
