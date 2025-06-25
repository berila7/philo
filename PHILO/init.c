/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 21:43:26 by mberila           #+#    #+#             */
/*   Updated: 2025/06/25 21:43:28 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	init_philosophers(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		table->philos[i].id = i + 1;
		table->philos[i].meals_eaten = 0;
		table->philos[i].last_meal_time = get_time();
		table->philos[i].left_fork = &table->forks[i];
		table->philos[i].right_fork = &table->forks[(i + 1) % table->philo_nbr];
		table->philos[i].table = table;
		i++;
	}
}

void	create_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		if (pthread_create(&table->philos[i].thread,
				NULL, philo_routine, &table->philos[i]) != 0)
			clean_exit("Thread creation failed", table);
		i++;
	}
}

int	ini_forks(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		if (pthread_mutex_init(&table->forks[i], NULL) != 0)
		{
			while (--i >= 0)
				pthread_mutex_destroy(&table->forks[i]);
			free(table->forks);
			free(table->philos);
			return (0);
		}
		i++;
	}
	return (1);
}

int	init_table(t_table *table)
{
	table->philos = malloc(sizeof(t_philo) * table->philo_nbr);
	if (!table->philos)
		return (0);
	table->forks = malloc(sizeof(pthread_mutex_t) * table->philo_nbr);
	if (!table->forks)
	{
		free(table->philos);
		return (0);
	}
	if (!ini_forks(table))
		return (0);
	if (pthread_mutex_init(&table->print, NULL) != 0)
		return (0);
	if (pthread_mutex_init(&table->death_check, NULL) != 0)
		return (0);
	init_philosophers(table);
	return (1);
}
