/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berila <berila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/19 13:05:24 by berila            #+#    #+#             */
/*   Updated: 2025/06/19 14:26:14 by berila           ###   ########.fr       */
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
			free(table->philos);
		free(table);
	}
}
