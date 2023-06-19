/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 10:51:10 by nel-baz           #+#    #+#             */
/*   Updated: 2023/06/19 08:10:38 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>

typedef struct data
{
	int				num_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				num_eat;
	long			first_time;
	pthread_mutex_t	*print;
}	t_data;

typedef struct philo
{
	pthread_t		thread_id;
	int				philo_id;
	int				num_e;
	long			last_time_eat;
	t_data			*time;
	pthread_mutex_t	fork;
	pthread_mutex_t	time_m;
	pthread_mutex_t	n_eat;
	pthread_mutex_t	*print;
	struct philo	*next;
}	t_philo;

int		check_num_eat(t_philo *philo);
int		ft_atoi(char *str);
t_philo	*ft_remplir(t_philo *philo, t_data *t);
int		ft_add_args(t_data *data, char **av);
long	get_time(void);
void	ft_usleep(long current_time, int time_to_sleep);
void	ft_print(char *str, t_philo *phil, int is_deid);
int		is_died(t_philo *phil);
void	ft_sleep_think(t_philo *phil);
void	ft_print(char *str, t_philo *phil, int f);
void	ft_eat(t_philo *phil);
void	free_list(t_philo **phil);
void	destroy_mutex(t_philo *phil);

#endif