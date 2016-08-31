#**************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: wgulista <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2016/07/12 16:11:57 by wgulista          #+#    #+#              #
#*   Updated: 2016/07/20 15:50:13 by                  ###   ########.fr       *#
#                                                                              #
# **************************************************************************** #

.PHONY: all, clean, fclean, re

NAME = fractol
LIBFT = libft.a
MINILIBX = minilibx.a
SRC_NAME = main.c error.c env.c key_hook.c display.c move.c \
			mandelbrot.c julia.c burnship.c mouse.c mouse_motion.c
OBJ_PATH = obj
SRC_PATH = srcs

CFLAGS = -Wall -Wextra -Werror -g3

OBJ = $(addprefix $(OBJ_PATH)/, $(SRC_NAME:.c=.o))
LIBX = -lm -L libft/ -lft -I/usr/local/include -I/usr/local/lib \
	   -Lminilibx/ -lmlx -framework OpenGL -framework AppKit

all: $(NAME)

$(NAME): $(LIBFT) $(MINILIBX) $(OBJ)
		@gcc $(LIBX) $(OBJ) -o $(NAME)
		@echo "\033[32mCompiling" [ $(NAME) ]"\033[0m"

$(LIBFT):
		@make -C ./libft/

$(MINILIBX):
		@make -C ./minilibx/

$(addprefix $(OBJ_PATH)/, %.o): $(addprefix $(SRC_PATH)/, %.c)
		@mkdir -p $(OBJ_PATH)
		@gcc $(CFLAGS) -o $@ -c $^
		@echo "\033[33mLinking" [ $< ] "\033[0m"

norme:
	@echo "\033[33mNorme LIBFT\033[0m"
	@norminette ./libft/*
	@echo "\n\033[33mNorme includes/fractal.h\033[0m"
	@norminette ./includes/fdf.h
	@echo "\n\033[33mNorme sources FRACTOL\033[0m"
	@norminette ./srcs

clean:
		@rm -fv $(OBJ)
		@rm -Rf $(OBJ_PATH)
		@make clean -C ./libft/
		@make clean -C ./minilibx/
		@echo "\033[31mCleaning" [ $(NAME) ] "...\033[0m"

fclean: clean
		@rm -fv $(NAME)
		@make fclean -C ./libft/
		@echo "\033[31mDelete" [ $(NAME) ] "\033[0m"

re: fclean all
