/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:11:55 by berila            #+#    #+#             */
/*   Updated: 2025/06/21 11:45:56 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	think(t_philo *philo)
{
	printf_status(philo, "is thinking");
}

void	take_forks(t_philo *philo)
{
	pthread_mutex_lock(philo->left_fork);
	printf_status(philo, "has taken the left fork");
	pthread_mutex_lock(philo->right_fork);
	printf_status(philo, "has taken the right fork");
}

void	eat(t_philo *philo)
{
	printf_status(philo, "is eating");
	pthread_mutex_lock(&philo->table->death_check);
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
	pthread_mutex_unlock(&philo->table->death_check);
	ft_usleep(philo->table->time_to_eat);
}

void	put_forks(t_philo *philo)
{
	pthread_mutex_unlock(philo->left_fork);	
	pthread_mutex_unlock(philo->right_fork);	
}

void	sleep_time(t_philo *philo)
{
	printf_status(philo, "is sleeping");
	ft_usleep(philo->table->time_to_sleep);	
}