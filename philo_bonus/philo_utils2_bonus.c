/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils2_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:26:43 by nel-baz           #+#    #+#             */
/*   Updated: 2023/06/19 08:53:38 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

int	ft_open_sem(char *str, t_philo *phil)
{
	int		i;
	char	*tmp;

	i = 0;
	tmp = str;
	while (i < phil->time->num_philo)
	{
		str = ft_strjoin(tmp, (i + 48));
		sem_unlink(str);
		phil->time_m = sem_open(str, O_CREAT, 0644, 1);
		if (phil->time_m == SEM_FAILED)
			return (0);
		phil = phil->next;
		i++;
		free (str);
	}
	return (1);
}

int	open_my_sems(t_philo *phil)
{
	sem_unlink("/my_sem");
	phil->time->fork = sem_open
		("/my_sem", O_CREAT, 0644, phil->time->num_philo);
	if (!ft_open_sem("/time_m", phil))
		return (0);
	sem_unlink("/print");
	phil->time->print = sem_open("/print", O_CREAT, 0644, 1);
	sem_unlink("/wait_dead");
	phil->time->wait_dead = sem_open("/wait_dead", O_CREAT, 0644, 0);
	sem_unlink("/wait_done");
	phil->time->wait_done = sem_open("/wait_done", O_CREAT, 0644, 0);
	if (phil->time->fork == SEM_FAILED || phil->time->print == SEM_FAILED
		|| phil->time->wait_dead == SEM_FAILED
		|| phil->time->wait_done == SEM_FAILED)
		return (0);
	return (1);
}

void	kill_proce(t_philo *phil)
{
	int	i;

	i = 0;
	while (i < phil->time->num_philo)
	{
		kill(phil->pid, SIGINT);
		phil = phil->next;
		i++;
	}
}
