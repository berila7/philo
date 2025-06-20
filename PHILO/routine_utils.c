/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   routine_utils.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berila <berila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/20 17:11:55 by berila            #+#    #+#             */
/*   Updated: 2025/06/20 18:06:23 by berila           ###   ########.fr       */
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
	philo->last_meal_time = get_time();
	philo->meals_eaten++;
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