/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_remplir_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/07 16:00:19 by nel-baz           #+#    #+#             */
/*   Updated: 2023/06/11 14:44:36 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

t_philo	*ft_lstnew(t_data *t, int id)
{
	t_philo	*node;

	node = malloc(sizeof(t_philo));
	if (!node)
		return (NULL);
	node->time = t;
	node->philo_id = id;
	node->next = NULL;
	node->num_e = 0;
	node->last_time_eat = 0;
	return (node);
}

t_philo	*ft_addback(t_philo *philo, t_data *t, int id)
{
	t_philo	*new;
	t_philo	*tmp;

	if (philo == NULL)
		return (ft_lstnew(t, id));
	tmp = philo;
	while (tmp->next)
		tmp = tmp->next;
	new = ft_lstnew(t, id);
	tmp->next = new;
	return (philo);
}

t_philo	*ft_remplir(t_philo *philo, t_data *t)
{
	int		i;
	t_philo	*tmp;

	i = 1;
	while (i <= t->num_philo)
	{
		philo = ft_addback(philo, t, i);
		i++;
	}
	tmp = philo;
	while (tmp->next)
		tmp = tmp->next;
	tmp->next = philo;
	return (philo);
}
