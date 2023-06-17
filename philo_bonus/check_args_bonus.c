/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:06:35 by nel-baz           #+#    #+#             */
/*   Updated: 2023/06/17 17:26:35 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_add_args(t_data *data, char **av)
{
	data->num_philo = ft_atoi(av[1]);
	if (data->num_philo <= 0)
		return (-1);
	data->t_die = ft_atoi(av[2]);
	if (data->t_die == -1)
		return (-1);
	data->t_eat = ft_atoi(av[3]);
	if (data->t_eat == -1)
		return (-1);
	data->t_sleep = ft_atoi(av[4]);
	if (data->t_sleep == -1)
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

void	*ft_check_num_eat(void *arg)
{
	t_philo	*phil;
	int		i;

	i = 0;
	phil = (t_philo *)arg;
	while (i < phil->time->num_philo)
	{
		sem_wait(phil->time->wait_done);
		i++;
	}
	sem_post(phil->time->wait_dead);
	sem_wait(phil->time->print);
	exit(0);
}

void	*is_died(void *arg)
{
	long	a;
	t_philo	*phil;

	phil = (t_philo *) arg;
	while (1)
	{
		sem_wait(phil->time_m);
		a = (get_time() - phil->time->first_time) - phil->last_time_eat;
		sem_post(phil->time_m);
		if (a >= phil->time->t_die)
		{
			sem_wait(phil->time->print);
			printf("\e[0;31m%ldms\t\t%d\tis dead\e[0;0m\n",
				(get_time() - phil->time->first_time), phil->philo_id);
			sem_post(phil->time->wait_dead);
			exit(0);
		}
	}
	return (NULL);
}
