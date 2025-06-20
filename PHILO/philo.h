/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berila <berila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:14:07 by mberila           #+#    #+#             */
/*   Updated: 2025/06/20 17:58:49 by berila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

#include <pthread.h>
#include <unistd.h>
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <sys/time.h>
#include <limits.h>

# define RED "\033[0;31m"
# define GREEN "\033[0;32m"
# define YELLOW "\033[0;33m"
# define BLUE "\033[0;34m"
# define MAGENTA "\033[0;35m"
# define CYAN "\033[0;36m"
# define RESET "\033[0m"

typedef struct s_table t_table;
typedef struct s_philo t_philo;
/*
- TABLE 
- ARGS: ./philo 5 800 200 200 [5]
*/

struct s_philo
{
	int			id;
	int			meals_eaten;
	long 		last_meal_time;
	pthread_t	thread;
	pthread_mutex_t	*left_fork;
	pthread_mutex_t	*right_fork;
	t_table		*table;
};

struct s_table
{
	int				philo_nbr;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	t_philo			*philos;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print;
	pthread_mutex_t	death_check;
	long			start_time;
	int				simulation_running;
};

int		parse_arguments(int ac, char *av[], t_table *table);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		init_table(t_table *table);
void	free_table(t_table *table);
void	*philo_routine(void *arg);
void	clean_exit(char *str, t_table *table);
void	create_threads(t_table *table);
void	printf_status(t_philo *philo, char *status);
long	get_time(void);
void	ft_usleep(long time);

void	think(t_philo *philo);
void	take_forks(t_philo *philo);
void	eat(t_philo *philo);
void	put_forks(t_philo *philo);
void	sleep_time(t_philo *philo);
void	*monitor_routine(void *arg);
#endif
