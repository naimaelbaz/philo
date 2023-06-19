/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo_bonus.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nel-baz <nel-baz@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/06/11 14:45:24 by nel-baz           #+#    #+#             */
/*   Updated: 2023/06/19 08:11:24 by nel-baz          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_BONUS_H
# define PHILO_BONUS_H

# include <pthread.h>
# include <stdio.h>
# include <stdlib.h>
# include <sys/time.h>
# include <unistd.h>
# include <signal.h>
# include <semaphore.h>

typedef struct data
{
	int				num_philo;
	int				t_die;
	int				t_eat;
	int				t_sleep;
	int				num_eat;
	long			first_time;
	sem_t			*fork;
	sem_t			*wait_dead;
	sem_t			*wait_done;
	sem_t			*print;
}	t_data;

typedef struct philo
{
	pthread_t		thread_id;
	int				philo_id;
	int				num_e;
	long			last_time_eat;
	t_data			*time;
	sem_t			*time_m;
	sem_t			*n_eat;
	struct philo	*next;
	int				pid;
}	t_philo;

int		ft_atoi(char *str);
t_philo	*ft_remplir(t_philo *philo, t_data *t);
int		ft_add_args(t_data *data, char **av);
long	get_time(void);
void	ft_usleep(long current_time, int time_to_sleep);
void	*is_died(void *phil);
void	ft_sleep_think(t_philo *phil);
void	ft_print(char *str, t_philo *phil);
void	ft_eat(t_philo *phil);
char	*ft_strjoin(char *s1, char s2);
int		ft_strlen(char *str);
void	*ft_check_num_eat(void *arg);
int		open_my_sems(t_philo *phil);
void	kill_proce(t_philo *phil);

#endif