/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:58:50 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/04 12:35:46 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

int	main(int argc, char **argv)
{
	(void)argv;
	if (argc == 5 || argc == 6)
	{
		if (check_input(argc, argv) != 0)
			return (1);
		printf("todos os argumentos estão corretos :D\n");
	}
	else
	{
		error_message("Insert five or six arguments for the philosophical dinner.");
		return (1);
	}
	return (0);
}
