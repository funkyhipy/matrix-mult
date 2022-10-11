cmake_minimum_required(VERSION 3.16)
project(matrix_mult C)

set(CMAKE_C_STANDARD 99)

add_executable(matrix_mult
        src/draw_1.c
        src/draw_2.c
        src/draw_3.c
        src/hmap.c
        src/hmap_to_matrix.c
        src/hooks.c
        src/init.c
        src/main.c
        src/matrix_1.c
        src/matrix_2.c
        src/matrix_3.c
        src/project_1.c
        src/project_2.c
        src/read_file_1.c
        src/read_file_2.c
        src/vector_1.c
        src/vector_2.c)

target_include_directories(matrix_mult PRIVATE incl)
target_include_directories(matrix_mult PRIVATE libft/incl)
target_include_directories(matrix_mult PRIVATE mlx_linux)


target_link_libraries(matrix_mult ${CMAKE_SOURCE_DIR}/libft/libft.a)
target_link_libraries(matrix_mult ${CMAKE_SOURCE_DIR}/mlx_linux/libmlx_Linux.a)

target_link_libraries(matrix_mult m)
target_link_libraries(matrix_mult Xext)
target_link_libraries(matrix_mult X11)
target_link_libraries(matrix_mult z)
target_link_libraries(matrix_mult bsd)
