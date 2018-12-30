# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2018/11/07 14:08:29 by dilaouid          #+#    #+#              #
#    Updated: 2018/12/30 15:11:11 by dilaouid         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME =	libft.a

SRC = 	ft_atoi.c ft_bzero.c ft_isalnum.c ft_isalpha.c ft_isascii.c ft_isdigit.c \
		ft_isprint.c ft_itoa.c ft_memalloc.c ft_memccpy.c ft_memchr.c ft_memcmp.c \
		ft_memcpy.c ft_memdel.c ft_memmove.c ft_memset.c ft_putchar.c ft_putchar_fd.c \
		ft_putstr.c ft_putstr_fd.c ft_putendl.c ft_putendl_fd.c ft_putnbr.c \
		ft_putnbr_fd.c ft_strcat.c ft_strncat.c ft_strchr.c ft_strclr.c ft_strcmp.c \
		ft_strncmp.c ft_strcpy.c ft_strncpy.c ft_strdel.c ft_strdup.c ft_strequ.c \
		ft_strnequ.c ft_striter.c ft_striteri.c ft_strjoin.c ft_strlcat.c ft_strlen.c \
		ft_strmap.c ft_strmapi.c ft_strnew.c ft_strrchr.c ft_strsplit.c ft_strstr.c \
		ft_strsub.c ft_strtrim.c ft_tolower.c ft_tolower_ultimate.c ft_toupper.c ft_strnstr.c \
		ft_lstdel.c ft_lstadd.c ft_lstiter.c ft_lstdelone.c ft_countwords.c ft_toupper_ultimate.c \
		ft_islower.c ft_isupper.c ft_countchar.c ft_strrev.c ft_lstnew.c \
		ft_nbchiffres.c ft_strndup.c ft_strnlen.c ft_sqrt.c get_next_line.c

O =		$(SRC:.c=.o)

all: $(NAME)

CFLAGS = -Wall -Werror -Wextra

$(NAME):	$(O)
	ar rc $(NAME) $(O)

clean:
	/bin/rm -f $(O)

fclean: clean
	/bin/rm -f $(NAME)

re: fclean all

.PHONY:	all clean re fclean
