/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:27:18 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/05 11:53:21 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	data_init(t_table *table)
{
	table->philos = allocate_memory(sizeof (t_philo) * table->philo_nbr);
	table->forks = allocate_memory(sizeof (t_philo) * table->philo_nbr);
	// table->start_simulation = 
	// table->end_simulation =
}

void	*allocate_memory(int bytes)
{
	void	*memory;

	memory = malloc(bytes);
	if (!memory)
		return (NULL);
	return (memory);
}
