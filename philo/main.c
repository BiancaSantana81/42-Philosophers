/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:58:50 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/07 16:57:19 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{	
	t_table	*table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (1);
	if (argc == 5 || argc == 6)
	{
		prepare_dinner_table(argc, argv, table);
		print_table(table);
	}
	else
		error_message("Insert five or six arguments.", table);
	free(table);
	return (0);
}
