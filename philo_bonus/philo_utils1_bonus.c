/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils1_bonus.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/21 19:20:23 by nel-baz           #+#    #+#             */
/*   Updated: 2023/06/18 21:12:06 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

void	ft_print(char *str, t_philo *phil)
{
	sem_wait(phil->time->print);
	printf("%ldms\t\t%d\t%s\n",
		(get_time() - phil->time->first_time), phil->philo_id, str);
	sem_post(phil->time->print);
}

void	ft_sleep_think(t_philo *phil)
{
	ft_print("is sleeping", phil);
	ft_usleep(get_time(), phil->time->t_sleep);
	ft_print("is thinking", phil);
}

void	ft_eat(t_philo *phil)
{
	sem_wait(phil->time->fork);
	ft_print("has taken a fork", phil);
	sem_wait(phil->time->fork);
	ft_print("has taken a fork", phil);
	ft_print("is eating", phil);
	phil->num_e++;
	if (phil->time->num_eat > 0 && phil->num_e == (phil->time->num_eat))
		sem_post(phil->time->wait_done);
	sem_wait(phil->time_m);
	phil->last_time_eat = get_time();
	sem_post(phil->time_m);
	ft_usleep(get_time(), phil->time->t_eat);
	sem_post(phil->time->fork);
	sem_post(phil->time->fork);
}
