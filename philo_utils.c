/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_utils.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 11:14:41 by nel-baz           #+#    #+#             */
/*   Updated: 2023/05/22 13:48:53 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	ft_strlen(char *str)
{
	int	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

int	ft_helper(char *str)
{
	int	i;

	i = 0;
	while (str && (str[i] == 32 || (str[i] >= 9 && str[i] <= 13)))
		i++;
	if (str && str[i] == '\0')
		return (printf("\e[0;31minvalid value 😵\e[0;0m\n"), -1);
	if (str[i] == '+' && (str[i + 1] >= '0' && str[i + 1] <= '9'))
		i++;
	return (i);
}

int	ft_atoi(char *str)
{
	int				i;
	int				j;
	unsigned long	res;

	res = 0;
	i = ft_helper(str);
	j = ft_strlen(str) - 1;
	while (str && (str[j] == 32 || (str[j] >= 9 && str[j] <= 13)))
		j--;
	while (i <= j)
	{
		if (str[i] < '0' || str[i] > '9')
			return (printf("\e[0;31minvalid value 😵\e[0;0m\n"), -1);
		else if (str[i] && (str[i] >= '0' && str[i] <= '9'))
			res = res * 10 + (str[i] - 48);
		i++;
	}
	if ((res > 2147483647))
		return (printf("\e[0;31minvalid value 😵\e[0;0m\n"), -1);
	return (res);
}

long	get_time(void)
{
	struct timeval	tv;

	gettimeofday(&tv, NULL);
	return (((tv.tv_sec * 1000) + (tv.tv_usec / 1000)));
}

void	ft_usleep(long current_time, int time_to_sleep)
{
	while (get_time() < (current_time + time_to_sleep))
		usleep(100);
}
