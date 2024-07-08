/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   1.check_input.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:33:50 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/08 15:58:18 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	everything_on_the_table(t_table *table, long int number, int index)
{
	if (index == 1)
		table->philo_nbr = number;
	else if (index == 5)
		table->nbr_limits_mails = number;
	else
	{
		if (number < 60)
			error_message("Our dinner doesn't need to be so fast!", table);
		number *= 1000;
		if (index == 2)
			table->time_to_die = number;
		else if (index == 3)
			table->time_to_eat = number;
		else if (index == 4)
			table->time_to_sleep = number;
	}
	if (table->philo_nbr > 200)
		error_message("Dammit! Do you want over 200 threads running?", table);
}

void	prepare_dinner_table(int argc, char **input, t_table *table)
{
	long int	number;
	int			i;

	i = 1;
	while (i < argc)
	{
		if (is_number(input[i]) != 0)
			error_message("Enter only numeric values.", table);
		number = ft_atol(input[i]);
		if (number < 0)
			error_message("No negativity at our dinner party, okay?", table);
		if (number == 0 && !(argc == 6 && i == 5))
			error_message("How do you expect our dinner to be free?", table);
		if (number > INT_MAX)
			error_message("The amount entered is very high.", table);
		everything_on_the_table(table, number, i);
		i++;
	}
	data_init(table);
}

int	is_number(char *input)
{
	int	i;

	i = 0;
	if (input[0] == '+' || input[0] == '-')
		i++;
	if (input[i] == '\0')
		return (1);
	while (input[i])
	{
		while ((input[i] >= 9 && input[i] <= 13) || input[i] == 32)
			i++;
		if (!ft_isdigit(input[i]))
			return (1);
		i++;
	}
	return (0);
}

int	ft_isdigit(int c)
{
	if (c >= '0' && c <= '9')
		return (1);
	else
		return (0);
}

long int	ft_atol(const char *nptr)
{
	int			i;
	long		r;
	int			sign;

	i = 0;
	r = 0;
	sign = 1;
	while (nptr[i] == ' ' || nptr[i] == '\n' || nptr[i] == '\t'
		|| nptr[i] == '\v' || nptr[i] == '\f' || nptr[i] == '\r')
	{
		i++;
	}
	if (nptr[i] == '-')
	{
		sign = -1;
		i++;
	}
	else if (nptr[i] == '+')
		i++;
	while (nptr[i] >= '0' && nptr[i] <= '9')
	{
		r = r * 10 + (nptr[i] - '0');
		i++;
	}
	return (r * sign);
}
