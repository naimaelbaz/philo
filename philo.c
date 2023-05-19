/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:50:51 by nel-baz           #+#    #+#             */
/*   Updated: 2023/05/19 16:01:01 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	is_died(t_philo *phil)
{
	long	a;

	while (phil)
	{
		a = (get_time() - phil->time->first_time) - phil->last_time_eat;
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

void	ft_print(char *str, t_philo *phil, int f)
{
	static int	n;

	pthread_mutex_lock(&phil->time->print);
	if (f)
	{
		n = 1;
		if (f == 1)
			printf("\e[0;31m%ldms\t\t%d\tis dead\e[0;0m\n",
				(get_time() - phil->time->first_time), phil->philo_id);
	}
	if (!n)
	{
		printf("%ldms\t\t%d\t%s\n",
			(get_time() - phil->time->first_time), phil->philo_id, str);
	}
	pthread_mutex_unlock(&phil->time->print);
}

void	*ft_routine(void *arg)
{
	t_philo			*phil;

	phil = (t_philo *) arg;
	while (1)
	{
		if (phil->philo_id % 2 != 0)
			usleep(100);
		pthread_mutex_lock(&phil->fork);
		ft_print("has taken a fork", phil, 0);
		pthread_mutex_lock(&phil->next->fork);
		ft_print("has taken a fork", phil, 0);
		phil->last_time_eat = get_time() - phil->time->first_time;
		ft_print("is eating", phil, 0);
		ft_usleep(get_time(), phil->time->t_eat);
		pthread_mutex_unlock(&phil->fork);
		pthread_mutex_unlock(&phil->next->fork);
		ft_print("is sleeping", phil, 0);
		ft_usleep(get_time(), phil->time->t_sleep);
		ft_print("is thinking", phil, 0);
		phil->num_e++;
		if (phil->time->num_eat != -1 && phil->num_e == phil->time->num_eat)
			break ;
	}
	return (NULL);
}

int	check_num_eat(t_philo *philo)
{
	int	i;

	i = 0;

	while (i < philo->time->num_philo)
	{
		if (philo->num_e != philo->time->num_eat)
			break ;
		i++;
	}
	if (i == philo->time->num_philo)
		return (1);
	return (0);
}

int	main(int ac, char **av)
{
	t_philo		*phil;
	t_data		data;
	int			i;

	if (ac == 6 || ac == 5)
	{
		phil = NULL;
		if (ft_add_args(&data, av) == -1)
			return (0);
		phil = ft_remplir(phil, &data);
		data.first_time = get_time();
		pthread_mutex_init(&data.print, NULL);
		i = 0;
		while (i < data.num_philo)
		{
			if (pthread_create(&phil->thread_id,
					NULL, ft_routine, phil) != 0)
				return (0);
			pthread_detach(phil->thread_id);
			phil = phil->next;
			i++;
		}
		is_died(phil);
	}
	else
		return (printf("\e[0;31minvalid number of args😵\e[0;0m\n"), 0);
	return (0);
}
