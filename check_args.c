/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:06:35 by nel-baz           #+#    #+#             */
/*   Updated: 2023/05/18 17:02:37 by nel-baz          ###   ########.fr       */
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
		if (data->num_eat == -1)
			return (-1);
	}
	else
		data->num_eat = -1;
	return (0);
}
