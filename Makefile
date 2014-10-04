# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: mdiouf <mdiouf@student.42.fr>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2014/04/20 23:02:19 by mdiouf            #+#    #+#              #
#    Updated: 2014/10/04 00:54:18 by mdiouf           ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = ft_ls

SRCS = ft_ls.c \
		ft_ls_1.c \
		ft_ls_2.c \
		ft_ls_3.c \
		ft_ls_4.c

OBJS = $(SRCS:.c=.o)

FLAGS = -Wall -Wextra -Werror

.PHONY: all, clean, fclean, re

all: $(NAME)

make:
	make -C libft/

$(NAME): $(OBJS)
	gcc -o $(NAME) $(OBJS) -L libft/ -lft -g

%.o : %.c
	make -C libft/
	gcc -I libft/includes/ $(FLAGS) -c $^ -g

clean:
	make -C libft/ clean
	/bin/rm -f $(OBJS)

fclean: clean
	make -C libft/ fclean
	/bin/rm -f $(NAME)

re: fclean all
