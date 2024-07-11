/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   6.clean.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/11 15:41:19 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/11 15:57:24 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	free_everything(t_table *table)
{
	if (table->philo)
		free(table->philo);
	if (table->fork)
		free(table->fork);
	if (table)
		free(table);
}

void	destroy_mutexes(t_table *table)
{
	int	i;
	int	j;

	i = 0;
	j = 0;
	if (pthread_mutex_destroy(&table->print) != 0)
		error_message("Error destroying print mutex.", table);
	if (pthread_mutex_destroy(&table->end_simulation_mutex) != 0)
		error_message("Error destroying end mutex.", table);
	while (i < table->philo_nbr)
	{
		if (pthread_mutex_destroy(&table->fork[i].fork) != 0)
			error_message("Error destroying fork mutex.", table);
		i++;
	}
	while (j < table->philo_nbr)
	{
		if (pthread_mutex_destroy(&table->philo[j].meals_counter_mutex) != 0)
			error_message("Error destroying meals_counter.", table);
		else if (pthread_mutex_destroy(
				&table->philo[j].last_meal_time_mutex) != 0)
			error_message("Error destroying last_meal_time.", table);
		j++;
	}
}
