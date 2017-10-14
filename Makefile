# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mvann <mvann@student.42.fr>                +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/09/18 12:17:58 by mvann             #+#    #+#              #
#    Updated: 2017/10/12 16:44:01 by mvann            ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = fdf
COMP_FLAGS = -Wall -Wextra -Werror
LIBFT = -L libft/ -lft
MINILIBX_DIR = minilibx_macos/
MINILIBX = -L $(MINILIBX_DIR) -lmlx -framework OpenGL -framework AppKit
SRC = fdf.c\
parse.c\
draw.c\
calculations.c\
events.c\
controller.c

all: $(NAME)

$(NAME):
	@cd libft/ && make
	@cd minilibx_macos/ && make
	@gcc $(COMP_FLAGS) -o $(NAME) $(SRC) $(LIBFT) $(MINILIBX)

clean:
	@rm -f $(SRC:.c=.o)
	@cd libft/ && make clean
	@cd $(MINILIBX_DIR) && make clean

fclean: clean
	@rm -f $(NAME)
	@cd libft/ && make fclean

re: fclean all

test:
	@gcc $(COMP_FLAGS) -o $(NAME) $(SRC) $(LIBFT) $(MINILIBX)
	@./fdf 42.fdf

man:
	@cd $(MINILIBX_DIR) && cd man && man -M . mlx

manloop:
	@cd $(MINILIBX_DIR) && cd man && man -M . mlx_loop
