# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 10:33:44 by nel-baz           #+#    #+#              #
#    Updated: 2023/06/19 08:56:12 by nel-baz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

FLAGS = -Wall -Werror -Wextra 

SRCS =	check_args.c \
		ft_remplir.c \
		philo.c \
		philo_utils.c \
		philo_utils1.c

OBJS = $(SRCS:.c=.o)

%.o: %.c philo.h
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME)

$(NAME):  $(OBJS)
	$(CC) $(FLAGS) $(OBJS) -o $(NAME)


clean:	
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all fclean clean re
