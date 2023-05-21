/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:50:51 by nel-baz           #+#    #+#             */
/*   Updated: 2023/05/21 20:36:56 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	*ft_routine(void *arg)
{
	t_philo			*phil;

	phil = (t_philo *) arg;
	while (1)
	{
		if (phil->philo_id % 2 == 0)
			usleep(100);
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
		if (!ft_continue(phil))
			break ;
	}
	return (NULL);
}

int	create_threads(t_philo *phil)
{
	int	i;

	i = 0;
	while (i < phil->time->num_philo)
	{
		if (pthread_create(&phil->thread_id,
				NULL, ft_routine, phil) != 0)
			return (0);
		pthread_detach(phil->thread_id);
		phil = phil->next;
		i++;
	}
	return (1);
}

int	main(int ac, char **av)
{
	t_philo		*phil;
	t_data		data;

	if (ac == 6 || ac == 5)
	{
		phil = NULL;
		if (ft_add_args(&data, av) == -1)
			return (0);
		data.print = malloc(sizeof(pthread_mutex_t));
		phil = ft_remplir(phil, &data);
		data.first_time = get_time();
		pthread_mutex_init(data.print, NULL);
		if (!create_threads(phil))
			return (0);
		if (!is_died(phil))
			return (0);
	}
	else
		return (printf("\e[0;31minvalid number of args😵\e[0;0m\n"), 0);
	return (0);
}
