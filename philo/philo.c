/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:50:51 by nel-baz           #+#    #+#             */
/*   Updated: 2023/06/19 08:10:47 by nel-baz          ###   ########.fr       */
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
		ft_eat(phil);
		ft_sleep_think(phil);
		pthread_mutex_lock(&phil->n_eat);
		phil->num_e++;
		if (phil->time->num_eat > 0 && phil->num_e == phil->time->num_eat)
		{
			pthread_mutex_unlock(&phil->n_eat);
			return (NULL);
		}
		pthread_mutex_unlock(&phil->n_eat);
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
		if (pthread_detach(phil->thread_id) != 0)
			return (0);
		phil = phil->next;
		i++;
	}
	return (1);
}

void	free_list(t_philo **phil)
{
	int		n;
	int		i;
	t_philo	*tmp;

	i = 0;
	n = (*phil)->time->num_philo;
	if (!phil || !(*phil))
		return ;
	while (i < n)
	{
		tmp = (*phil)->next;
		free(*phil);
		*phil = tmp;
		i++;
	}
	*phil = NULL;
}

void	destroy_mutex(t_philo *phil)
{
	int	i;

	i = 0;
	while (i < phil->time->num_philo)
	{
		pthread_mutex_destroy(&phil->fork);
		pthread_mutex_destroy(&phil->time_m);
		pthread_mutex_destroy(&phil->n_eat);
		pthread_mutex_destroy(phil->print);
		phil = phil->next;
		i++;
	}
	pthread_mutex_destroy(phil->time->print);
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
		if (!data.print)
			return (0);
		phil = ft_remplir(phil, &data);
		data.first_time = get_time();
		pthread_mutex_init(data.print, NULL);
		if (!create_threads(phil))
			return (0);
		is_died(phil);
	}
	else
		return (printf("\e[0;31minvalid number of args😵\e[0;0m\n"), 0);
	return (0);
}
