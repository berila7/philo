/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   monitor.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berila <berila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:29:09 by berila            #+#    #+#             */
/*   Updated: 2025/06/20 20:23:13 by berila           ###   ########.fr       */
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

void	*monitor_routine(void *arg)
{
	t_table	*table;
	int		i;
	int		all_ate_enough;

	table = (t_table *)arg;
	while (table->simulation_running)
	{
		if(death_check(table))
			break ;
		if (table->must_eat_count != -1)
		{
			all_ate_enough = 1;
			i = 0;
			while (i < table->philo_nbr)
			{
				if (table->philos[i].meals_eaten < table->must_eat_count)
				{
					all_ate_enough = 0;
					break;
				}
				i++;
			}
			if (all_ate_enough)
				table->simulation_running = 0;
		}
		usleep(1000);
	}
	return (NULL);
}
