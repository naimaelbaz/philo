/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:06:35 by nel-baz           #+#    #+#             */
/*   Updated: 2023/05/25 19:19:50 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_add_args(t_data *data, char **av)
{
	data->num_philo = ft_atoi(av[1]);
	data->t_die = ft_atoi(av[2]);
	data->t_eat = ft_atoi(av[3]);
	data->t_sleep = ft_atoi(av[4]);
	if (data->num_philo <= 0 || data->t_die == -1
		|| data->t_eat == -1 || data->t_sleep == -1)
		return (-1);
	if (av[5] != NULL)
	{
		data->num_eat = ft_atoi(av[5]);
		if (data->num_eat == -1 || data->num_eat == 0)
			return (-1);
	}
	else
		data->num_eat = -1;
	return (0);
}

int	check_num_eat(t_philo *philo)
{
	int	i;

	i = 0;
	while (i < philo->time->num_philo)
	{
		pthread_mutex_lock(&philo->n_eat);
		if (philo->num_e != philo->time->num_eat)
		{
			pthread_mutex_unlock(&philo->n_eat);
			break ;
		}
		i++;
		pthread_mutex_unlock(&philo->n_eat);
	}
	if (i == philo->time->num_philo)
		return (1);
	return (0);
}

int	is_died(t_philo *phil)
{
	long	a;

	while (1)
	{
		pthread_mutex_lock(&phil->time_m);
		a = (get_time() - phil->time->first_time) - phil->last_time_eat;
		pthread_mutex_unlock(&phil->time_m);
		if (a >= phil->time->t_die && phil->num_e != phil->time->num_eat)
		{
			ft_print("", phil, 1);
			break ;
		}
		if (check_num_eat(phil))
		{
			ft_print("", phil, 2);
			break ;
		}
		phil = phil->next;
	}
	return (0);
}
