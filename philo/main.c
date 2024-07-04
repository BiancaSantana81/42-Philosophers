/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:58:50 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/04 16:10:11 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{	
	t_table *table;

	table = malloc(sizeof(t_table));
	if (!table)
        return (1);
	if (argc == 5 || argc == 6)
	{
		if (check_input(argc, argv, table) != 0)
		{
			free(table);
			return (1);
		}
		print_table(table);
	}
	else
	{
		error_message("Insert five or six arguments for our dinner party.");
		free(table);
		return (1);
	}
	free(table);
	return (0);
}
