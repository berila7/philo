/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 21:44:40 by mberila           #+#    #+#             */
/*   Updated: 2025/06/26 12:50:41 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printf_status(t_philo *philo, char *status)
{
	long	current_time;

	pthread_mutex_lock(&philo->table->print);
	if (philo->table->simulation_running)
	{
		current_time = get_time() - philo->table->start_time;
		printf("%ld %d %s\n", current_time, philo->id, status);
	}
	pthread_mutex_unlock(&philo->table->print);
}

int	simulation_is_running(t_table *table)
{
	int	running;

	pthread_mutex_lock(&table->death_check);
	running = table->simulation_running;
	pthread_mutex_unlock(&table->death_check);
	return (running);
}

void	*philo_routine(void *arg)
{
	t_philo	*philo;

	philo = (t_philo *)arg;
	if (philo->table->philo_nbr == 1)
	{
		printf_status(philo, "has taken a fork");
		ft_usleep(philo->table->time_to_die);
		return (NULL);
	}
	while (simulation_is_running(philo->table))
	{
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		sleep_time(philo);
		think(philo);
	}
	return (NULL);
}
