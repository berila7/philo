/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 15:46:21 by berila            #+#    #+#             */
/*   Updated: 2025/06/21 11:50:04 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	printf_status(t_philo *philo, char *status)
{
	long current_time;

	pthread_mutex_lock(&philo->table->print);
	if (philo->table->simulation_running)
	{
		current_time = get_time() - philo->table->start_time;
		printf("%ld %d %s\n", current_time, philo->id, status);
	}
	pthread_mutex_unlock(&philo->table->print);
}

int	simulation_is_running(t_philo *philo)
{
	int running;

	pthread_mutex_lock(&philo->table->death_check);
	running = philo->table->simulation_running;
	pthread_mutex_unlock(&philo->table->death_check);
	return (running);
}

void	*philo_routine(void *arg)
{
	t_philo *philo;

	philo = (t_philo *)arg;
	if (philo->table->philo_nbr == 1)
	{
		printf_status(philo, "has taken a fork");
		ft_usleep(philo->table->time_to_die);
		return (NULL);
	}
	while (simulation_is_running(philo))
	{
		think(philo);
		take_forks(philo);
		eat(philo);
		put_forks(philo);
		sleep_time(philo);
	}
	return (NULL);
}