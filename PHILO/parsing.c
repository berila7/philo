/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: mberila <mberila@student.42.fr>            +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/05 10:56:22 by mberila           #+#    #+#             */
/*   Updated: 2025/04/06 11:00:01 by mberila          ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static int	is_digit(char *str)
{
	int	i;

	i = 0;
	if(!str)
		return (0);
	while (str[i])
	{
		if(str[i] >= '0' && str[i] <= '9')
			i++;
		else
			return (0);
	}
	return (1);
}

static long	ft_atol(char *str)
{
	int	i;
	long result;
	int sign;

	i = 0;
	result = 0;
	sign = 1;
	while (str[i] == ' ' || str[i] == '\t')
		i++;
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result *= 10;
		result += str[i] - '0';
		i++;
	}
	return (result * sign);
}

static int	within_limits(char *str)
{
	long	nbr;

	if (!str)
		return (0);
	nbr = ft_atol(str);
	if (nbr > INT_MAX || nbr < INT_MIN || nbr == 0)
		return (0);
	return (1);
}

int	parse_arguments(int ac, char *av[], t_table *table)
{
	int	i;

	i = 1;
	while (i < ac)
	{
		if (!is_digit(av[i]) || !within_limits(av[i]))
			return (0);
		i++;
	}
	return (1);
}
