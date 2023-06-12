/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin_bonus.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/10 16:42:20 by nel-baz           #+#    #+#             */
/*   Updated: 2023/06/11 14:44:36 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo_bonus.h"

char	*ft_strjoin(char *s1, char s2)
{
	char	*str;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	i = ft_strlen(s1);
	str = (char *)malloc((i + 2) * sizeof(char));
	if (!str)
		return (NULL);
	j = 0;
	while (s1[j])
	{
		str[j] = s1[j];
		j++;
	}
	str[j] = s2;
	j++;
	str[j] = '\0';
	return (str);
}
