#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: gmontaur <marvin@42lausanne.ch>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2021/07/14 22:29:13 by gmontaur          #+#    #+#              #
#    Updated: 2021/07/14 22:29:15 by gmontaur         ###   ########.fr        #
#                                                                              #
#******************************************************************************#
#export DISPLAY=$(cat /etc/resolv.conf | grep nameserver | awk '{print $2}'):0.0
#export DISPLAY=localhost:0.0
NAME = fdf

CC = gcc
FLAGS = -Wall -Werror -Wextra -pedantic

##################################################################
#LIBRARIES PART OF MAKEFILE
##################################################################
#MACOS LIBRARY MINILIBX
#MINILIBX_DIRECTORY = ./mlx_macos/
#LIBRARIES = -lmlx -lm -lft -L$(LIBFT_DIRECTORY) -L$(MINILIBX_DIRECTORY) -framework OpenGL -framework AppKit

#LINUX LIBRARY MINILIBX
LIBRARIES = -Lmlx_Linux -lmlx_Linux -L/usr/lib -Imlx_Linux -lXext -lX11 -lm -lz -lbsd -L$(LIBFT_DIRECTORY) -lft
MINILIBX_DIRECTORY = ./mlx_linux/

MINILIBX = $(MINILIBX_DIRECTORY)libmlx.a
#MINILIBX = $(MINILIBX_DIRECTORY)libmlx_Linux.a
MINILIBX_HEADERS = $(MINILIBX_DIRECTORY)

LIBFT_DIRECTORY = ./libft/
LIBFT = $(LIBFT_DIRECTORY)libft.a
LIBFT_HEADERS = $(LIBFT_DIRECTORY)incl/

INCLUDES = -I$(HEADERS_DIRECTORY) -I$(LIBFT_HEADERS) -I$(MINILIBX_HEADERS) -I/usr/include

##################################################################
#Header PART OF MAKEFILE
##################################################################
HEADERS_DIRECTORY = ./incl/
HEADERS_LIST = \
	draw.h \
	fdf.h \
	hmap.h \
	matrix.h \
	vector.h
HEADERS = $(addprefix $(HEADERS_DIRECTORY), $(HEADERS_LIST))

##################################################################
#Sources PART OF MAKEFILE
##################################################################
SOURCES_DIRECTORY = ./src/
SOURCES_LIST = \
	draw_1.c \
	draw_2.c \
	draw_3.c \
	hmap.c \
	hmap_to_matrix.c \
	hooks.c \
	init.c \
	main.c \
	matrix_1.c \
	matrix_2.c \
	matrix_3.c \
	project_1.c \
	project_2.c \
	read_file_1.c \
	read_file_2.c \
	vector_1.c \
	vector_2.c

SOURCES = $(addprefix $(SOURCES_DIRECTORY), $(SOURCES_LIST))

##################################################################
#Objects PART OF MAKEFILE
##################################################################
OBJECTS_DIRECTORY = objs/
OBJECTS_LIST = $(patsubst %.c, %.o, $(SOURCES_LIST))
OBJECTS	= $(addprefix $(OBJECTS_DIRECTORY), $(OBJECTS_LIST))

# COLORS
GREEN = \033[0;32m
RED = \033[0;31m
RESET = \033[0m

##################################################################
#Commands PART OF MAKEFILE
##################################################################
all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJECTS_DIRECTORY) $(OBJECTS)
	@$(CC) $(FLAGS) $(OBJECTS) $(LIBRARIES) $(INCLUDES) -o $(NAME)
	@echo "\n$(NAME): $(GREEN)object files were created$(RESET)"
	@echo "$(NAME): $(GREEN)$(NAME) was created$(RESET)"

$(OBJECTS_DIRECTORY):
	@mkdir -p $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(GREEN)$(OBJECTS_DIRECTORY) was created$(RESET)"

$(OBJECTS_DIRECTORY)%.o : $(SOURCES_DIRECTORY)%.c $(HEADERS)
	@$(CC) $(FLAGS) -c $(INCLUDES) $< -o $@
	@echo "$(GREEN).$(RESET)\c"

$(LIBFT):
	@echo "$(NAME): $(GREEN)Creating $(LIBFT)...$(RESET)"
	@$(MAKE) -sC $(LIBFT_DIRECTORY)

$(MINILIBX):
	@echo "$(NAME): $(GREEN)Creating $(MINILIBX)...$(RESET)"
	@$(MAKE) -sC $(MINILIBX_DIRECTORY)

clean:
	@$(MAKE) -sC $(LIBFT_DIRECTORY) clean
	@$(MAKE) -sC $(MINILIBX_DIRECTORY) clean
	@rm -rf $(OBJECTS_DIRECTORY)
	@echo "$(NAME): $(RED)$(OBJECTS_DIRECTORY) was deleted$(RESET)"
	@echo "$(NAME): $(RED)object files were deleted$(RESET)"

fclean: clean
	@rm -f $(MINILIBX)
	@echo "$(NAME): $(RED)$(MINILIBX) was deleted$(RESET)"
	@rm -f $(LIBFT)
	@echo "$(NAME): $(RED)$(LIBFT) was deleted$(RESET)"
	@rm -f $(NAME)
	@echo "$(NAME): $(RED)$(NAME) was deleted$(RESET)"

re: fclean all

.PHONY: all clean fclean re