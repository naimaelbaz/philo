/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:50:51 by nel-baz           #+#    #+#             */
/*   Updated: 2023/06/19 09:00:07 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_routine(t_philo *phil)
{
	pthread_create(&phil->thread_id, NULL, is_died, phil);
	pthread_detach(phil->thread_id);
	while (1)
	{
		ft_eat(phil);
		ft_sleep_think(phil);
	}
}

int	create_process(t_philo *phil)
{
	int	i;

	phil->time->first_time = get_time();
	i = 0;
	while (i < phil->time->num_philo)
	{
		phil->pid = fork();
		if (phil->pid == -1)
			return (0);
		if (phil->pid == 0)
		{
			ft_routine(phil);
			exit(1);
		}
		phil = phil->next;
		i++;
	}
	return (1);
}

int	check_eat(t_philo *phil)
{
	pthread_t	id;

	if (phil->time->num_eat)
	{
		if (pthread_create(&id, NULL, ft_check_num_eat, phil) != 0)
			return (0);
		if (pthread_detach(id) != 0)
			return (0);
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
		phil = ft_remplir(phil, &data);
		if (!open_my_sems(phil))
			return (0);
		if (!create_process(phil))
			return (0);
		check_eat(phil);
		waitpid(-1, 0, 0);
		sem_wait(phil->time->wait_dead);
		return (kill_proce(phil), 0);
	}
	else
		return (printf("\e[0;31minvalid number of args😵\e[0;0m\n"), 0);
	return (0);
}
