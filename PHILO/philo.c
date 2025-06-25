/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 21:43:58 by mberila           #+#    #+#             */
/*   Updated: 2025/06/25 21:44:00 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_exit(char *str, t_table *table)
{
	free_table(table);
	printf("%s", str);
	exit(EXIT_FAILURE);
}

void	join_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		pthread_join(table->philos[i].thread, NULL);
		i++;
	}
}

int	main(int ac, char *av[])
{
	t_table		*table;
	pthread_t	monitor;

	table = malloc(sizeof(t_table));
	if (!table)
		clean_exit("Allocation failed", NULL);
	memset(table, 0, sizeof(t_table));
	if (ac != 5 && ac != 6)
		clean_exit("Invalid arguments\n", table);
	if (!parse_arguments(ac, av, table))
		clean_exit("Ivalid arguments\n", table);
	if (!init_table(table))
		clean_exit("Initialization failed", table);
	table->start_time = get_time();
	table->simulation_running = 1;
	create_threads(table);
	if (pthread_create(&monitor, NULL, monitor_routine, table) != 0)
		clean_exit("Monitor thread creation failed", table);
	pthread_join(monitor, NULL);
	join_threads(table);
	free_table(table);
	return (0);
}
