#******************************************************************************#
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: dtelega <marvin@42.fr>                     +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2017/03/10 18:47:42 by dtelega           #+#    #+#              #
#    Updated: 2017/03/10 18:47:42 by dtelega          ###   ########.fr        #
#                                                                              #
#******************************************************************************#

NAME = filler

SRC = filler.c main.c get_data.c help_stuff.c get_next_line.c

OB = $(SRC:.c=.o)

FLAGS = -Wall -Wextra -Werror

all: $(NAME)

$(NAME): $(OB)
	cd libft/ && $(MAKE)
	gcc -o $(NAME) $(OB) libft/libft.a

%.o : %.c
	gcc $(FLAGS) -c $< -o $@

clean:
	rm -f $(OB)
	make clean libft/

fclean: clean
	rm -f $(NAME)
	make fclean libft/

re: fclean all 