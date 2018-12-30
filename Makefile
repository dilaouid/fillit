# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/12/30 14:56:21 by dilaouid          #+#    #+#              #
#    Updated: 2018/12/30 20:01:31 by aibatyrb         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME 	= 	fillit

SRC 	= 	srcs/checkpose.c srcs/checks.c srcs/main.c srcs/matrice.c srcs/read.c srcs/resolv.c 

CC		=	gcc

OBJ 	= 	$(SRC:.c=.o)

CFLAGS 	= 	-Wall -Wextra -Werror -Ilibft

all: libft/ $(NAME)

$(NAME): $(OBJ) libft Makefile
	make -C libft/
	$(CC) $(CFLAGS) $(OBJ) libft/libft.a -o $(NAME)

clean:
	/bin/rm -f $(OBJ)
	make clean -C libft/

fclean:
	/bin/rm -f $(OBJ)
	/bin/rm -f $(NAME)
	make fclean -C libft/

re: fclean all


.PHONY: all re clean fclean
