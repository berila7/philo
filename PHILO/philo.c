/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: berila <berila@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:47:22 by mberila           #+#    #+#             */
/*   Updated: 2025/06/20 18:41:37 by berila           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	clean_exit(char *str, t_table *table)
{
	free_table(table);
	printf(RED"%s"RESET, str);
	exit(EXIT_FAILURE);
}

int main(int ac, char *av[])
{
	t_table     *table;
    pthread_t   monitor;
	int		i;

	table = malloc(sizeof(t_table));
	if (!table)
		clean_exit("Allocation failed", NULL);
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
    i = 0;
    while (i < table->philo_nbr)
    {
        pthread_join(table->philos[i].thread, NULL);
        i++;
    }
//  // Test output - print philosopher info
//     printf("=== SIMULATION SETUP ===\n");
//     printf("Philosophers: %d\n", table->philo_nbr);
//     printf("Time to die: %d ms\n", table->time_to_die);
//     printf("Time to eat: %d ms\n", table->time_to_eat);
//     printf("Time to sleep: %d ms\n", table->time_to_sleep);
//     printf("Must eat count: %d\n", table->must_eat_count);
    
//     printf("\n=== PHILOSOPHERS ===\n");
//     i = 0;
//     while (i < table->philo_nbr)
//     {
//         printf("Philosopher %d: meals_eaten=%d\n", 
//                table->philos[i].id, 
//                table->philos[i].meals_eaten);
//         i++;
//     }
    
//     printf("\n=== FORKS INITIALIZED ===\n");
//     printf("Created %d fork mutexes\n", table->philo_nbr);
    
    free_table(table);
    return (0);
}
