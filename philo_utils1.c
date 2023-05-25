/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:20:23 by nel-baz           #+#    #+#             */
/*   Updated: 2023/05/25 19:12:04 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	ft_print(char *str, t_philo *phil, int f)
{
	static int	n;

	pthread_mutex_lock(phil->print);
	if (f)
	{
		n = 1;
		if (f == 1)
			printf("\e[0;31m%ldms\t\t%d\tis dead\e[0;0m\n",
				(get_time() - phil->time->first_time), phil->philo_id);
	}
	if (!n)
		printf("%ldms\t\t%d\t%s\n",
			(get_time() - phil->time->first_time), phil->philo_id, str);
	pthread_mutex_unlock(phil->print);
}

void	ft_sleep_think(t_philo *phil)
{
	ft_print("is sleeping", phil, 0);
	ft_usleep(get_time(), phil->time->t_sleep);
	ft_print("is thinking", phil, 0);
	pthread_mutex_lock(&phil->n_eat);
	phil->num_e++;
	pthread_mutex_unlock(&phil->n_eat);
}

void	ft_eat(t_philo *phil)
{
	pthread_mutex_unlock(&phil->n_eat);
	pthread_mutex_lock(&phil->fork);
	ft_print("has taken a fork", phil, 0);
	pthread_mutex_lock(&phil->next->fork);
	ft_print("has taken a fork", phil, 0);
	ft_print("is eating", phil, 0);
	pthread_mutex_lock(&phil->time_m);
	phil->last_time_eat = get_time() - phil->time->first_time;
	pthread_mutex_unlock(&phil->time_m);
	ft_usleep(get_time(), phil->time->t_eat);
	pthread_mutex_unlock(&phil->fork);
	pthread_mutex_unlock(&phil->next->fork);
}
