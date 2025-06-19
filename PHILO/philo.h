/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berila <berila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/17 17:14:07 by mberila           #+#    #+#             */
/*   Updated: 2025/06/19 14:26:17 by berila           ###   ########.fr       */
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

/*
- TABLE 
- ARGS: ./philo 5 800 200 200 [5]
*/

typedef struct s_philo
{
	int	id;
	int	meals_eaten;
}	t_philo;

typedef struct s_table
{
	int				philo_nbr;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				must_eat_count;
	t_philo			*philos;
	pthread_mutex_t	*forks;
}	t_table;

int		parse_arguments(int ac, char *av[], t_table *table);
int		ft_atoi(const char *str);
int		ft_isdigit(int c);
int		init_table(t_table *table);
void	free_table(t_table *table);

#endif
