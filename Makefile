# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 10:33:44 by nel-baz           #+#    #+#              #
#    Updated: 2023/05/25 15:18:01 by nel-baz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = philo

CC = cc

CFLAGS = -Wall -Werror -Wextra

SRCS = check_args.c ft_remplir.c philo.c philo_utils.c philo_utils1.c\

OBJS = $(SRCS:.c=.o)

%.o: %.c philo.h
	$(CC) $(CFLAGS) -c $< -o $@

all :  $(NAME)	

$(NAME):  $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)

clean:	
	rm -rf $(OBJS)

fclean:	clean
	rm -rf $(NAME)

re : fclean all

.PHONY : all fclean clean re
