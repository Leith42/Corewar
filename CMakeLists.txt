cmake_minimum_required(VERSION 3.9)
project(Corewar C)

set(CMAKE_C_STANDARD 99)

add_executable(Corewar
        vm/srcs/main.c
        vm/srcs/parsing.c
        )

include_directories(Corewar
        ${CMAKE_SOURCE_DIR}/vm/incs/
        ${CMAKE_SOURCE_DIR}/libft/incs/)

target_link_libraries(Corewar
${CMAKE_SOURCE_DIR}/libft/libft.a)