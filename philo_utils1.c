/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:20:23 by nel-baz           #+#    #+#             */
/*   Updated: 2023/05/21 20:33:29 by nel-baz          ###   ########.fr       */
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

int	ft_continue(t_philo *phil)
{
	ft_print("is sleeping", phil, 0);
	ft_usleep(get_time(), phil->time->t_sleep);
	ft_print("is thinking", phil, 0);
	pthread_mutex_lock(&phil->n_eat);
	phil->num_e++;
	if (phil->time->num_eat != -1 && phil->num_e == phil->time->num_eat)
	{
		pthread_mutex_unlock(&phil->n_eat);
		return (0);
	}
	pthread_mutex_unlock(&phil->n_eat);
	return (1);
}