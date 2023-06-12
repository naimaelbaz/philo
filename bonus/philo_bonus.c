/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:50:51 by nel-baz           #+#    #+#             */
/*   Updated: 2023/06/12 11:14:06 by nel-baz          ###   ########.fr       */
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
		phil->num_e++;
		if (phil->time->num_eat > 0 && phil->num_e == (phil->time->num_eat + 1))
		{
			sem_post(phil->time->wait_done);
			exit(0);
		}
	}
}

void	create_process(t_philo *phil)
{
	int	i;

	i = 0;
	phil->time->first_time = get_time();
	while (i < phil->time->num_philo)
	{
		phil->pid = fork();
		if (phil->pid == 0)
		{
			ft_routine(phil);
			exit (0);
		}
		phil = phil->next;
		i++;
	}
}

int	main(int ac, char **av)
{
	t_philo		*phil;
	t_data		data;
	pthread_t	id;

	if (ac == 6 || ac == 5)
	{
		phil = NULL;
		if (ft_add_args(&data, av) == -1)
			return (0);
		phil = ft_remplir(phil, &data);
		open_my_sems(phil);
		create_process(phil);
		waitpid(-1, 0, 0);
		if (data.num_eat)
			pthread_create(&id, NULL, ft_check_num_eat, phil);
		kill_proce(phil);
		sem_close(phil->time->fork);
	}
	else
		return (printf("\e[0;31minvalid number of args😵\e[0;0m\n"), 0);
	return (0);
}
