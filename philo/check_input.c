/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/04 12:33:50 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/04 12:38:18 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int check_input(int argc, char **input)
{
	int i;
	long long int number;

	i = 1;
	while (i < argc)
	{
		if (is_number(input[i]) != 0)
		{
			error_message("Enter only numeric values.");
			return (1);
		}
		number = ft_atol(input[i]);
		if (aux_check_input(number, argc, i) != 0)
			return (1);
		i++;
	}
	return (0);
}

int aux_check_input(int number, int argc, int i)
{
	if (number < 0)
	{
		error_message("No negativity at our dinner party, okay?");
		return (1);
	}
	if (number == 0 && !(argc == 6 && i == 5))
    {
        error_message("Really? How do you expect our dinner to be worth zero?");
        return 1;
    }
	if (number < INT_MIN || number > INT_MAX)
	{
		error_message("Values must be within the range of an int.");
		return (1);
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

int is_number(char *input)
{
	int i;

	i = 0;
	if (input[0] == '+' || input[0] == '-')
		i++;
	if (input[i] == '\0')
        return (1);
	while (input[i])
	{
		if (!ft_isdigit(input[i]))
			return (1);
		i++;
	}
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
