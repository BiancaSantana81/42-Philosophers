/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:57:48 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/08 16:25:29 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_message(char *string, t_table *table)
{
	printf(RED"🚨 "WHITE"%s"RED" 🚨\n"RST, string);
	free(table);
	exit(1);
}

void	*allocate_memory(int bytes)
{
	void	*memory;

	memory = malloc(bytes);
	if (!memory)
		return (NULL);
	return (memory);
}

void free_everything(t_table *table)
{
	if (table->philos)
		free(table->philos);
	if (table->forks)
		free(table->forks);
	if (table)
		free(table);
}
