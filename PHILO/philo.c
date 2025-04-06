/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/03/19 13:47:22 by mberila           #+#    #+#             */
/*   Updated: 2025/04/06 10:32:05 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "./philo.h"

void	clean_exit(char *str)
{
	printf(RED"%s"RESET, str);
	exit(EXIT_FAILURE);
}

int main(int ac, char *av[])
{
	t_table *table;

	table = NULL;
	(void)av;
	if (ac != 5 && ac != 6)
		clean_exit("Invalid number arguments\n");
	if (!parse_arguments(ac, av, table))
		clean_exit("Ivalid arguments");
	return (0);
}