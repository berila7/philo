/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 21:43:14 by mberila           #+#    #+#             */
/*   Updated: 2025/06/26 11:06:45 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_table(t_table *table)
{
	int	i;

	if (table)
	{
		if (table->forks)
		{
			i = 0;
			while (i < table->philo_nbr)
			{
				pthread_mutex_destroy(&table->forks[i]);
				i++;
			}
			free(table->forks);
		}
		if (table->philos)
		{
			pthread_mutex_destroy(&table->print);
			pthread_mutex_destroy(&table->death_check);
		}
		if (table->philos)
			free(table->philos);
		free(table);
	}
}
