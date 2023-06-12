# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2023/05/16 10:33:44 by nel-baz           #+#    #+#              #
#    Updated: 2023/06/12 11:29:23 by nel-baz          ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME_B = philo_bonus

CC = cc

FLAGS = -Wall -Werror -Wextra

SRCS_BONUS =	check_args_bonus.c \
				ft_strjoin_bonus.c \
				philo_utils2_bonus.c \
				ft_remplir_bonus.c \
				philo_bonus.c \
				philo_utils1_bonus.c \
				philo_utils_bonus.c

OBJS_BONUS = $(SRCS_BONUS:.c=.o)
	
%.o: %.c philo_bonus.h
	$(CC) $(FLAGS) -c $< -o $@

all : $(NAME_B)


$(NAME_B):  $(OBJS_BONUS)
	$(CC) $(FLAGS) $(OBJS_BONUS) -o $(NAME_B)

clean:	
	rm -rf $(OBJS_BONUS)

fclean:	clean
	rm -rf $(NAME_B)

re : fclean all

.PHONY : all fclean clean re
