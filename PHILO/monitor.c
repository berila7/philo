/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 21:43:34 by mberila           #+#    #+#             */
/*   Updated: 2025/06/26 10:22:59 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	death_check(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_mutex_lock(&table->death_check);
		if (get_time() - table->philos[i].last_meal_time > table->time_to_die)
		{
			table->simulation_running = 0;
			pthread_mutex_unlock(&table->death_check);
			pthread_mutex_lock(&table->print);
			printf("%ld %d died\n", get_time() - table->start_time,
				table->philos[i].id);
			pthread_mutex_unlock(&table->print);
			return (1);
		}
		pthread_mutex_unlock(&table->death_check);
		i++;
	}
	return (0);
}

int	meals_check(t_table *table)
{
	int	i;
	int	ate_enough;

	i = 0;
	ate_enough = 1;
	while (i < table->philo_nbr)
	{
		pthread_mutex_lock(&table->death_check);
		if (table->philos[i].meals_eaten < table->must_eat_count)
			ate_enough = 0;
		pthread_mutex_unlock(&table->death_check);
		if (!ate_enough)
			break ;
		i++;
	}
	return (ate_enough);
}

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		all_ate_enough;

	table = (t_table *)arg;
	while (simulation_is_running(table))
	{
		if (death_check(table))
			break ;
		if (table->must_eat_count != -1)
		{
			all_ate_enough = meals_check(table);
			if (all_ate_enough)
			{
				pthread_mutex_lock(&table->death_check);
				table->simulation_running = 0;
				pthread_mutex_unlock(&table->death_check);
			}
		}
		usleep(1000);
	}
	return (NULL);
}
