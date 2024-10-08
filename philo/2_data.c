/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2_data.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:27:18 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/15 13:35:47 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	data_init(t_table *table)
{
	int	i;

	i = 0;
	table->end_simulation = false;
	table->philo = allocate_memory(sizeof(t_philo) * table->philo_nbr);
	table->fork = allocate_memory(sizeof(t_fork) * table->philo_nbr);
	while (i < table->philo_nbr)
	{
		if (pthread_mutex_init(&table->fork[i].fork, NULL) != 0)
			error_message("Error initializing fork mutex.", table);
		table->fork[i].id = i;
		i++;
	}
	if (pthread_mutex_init(&table->print, NULL) != 0)
		error_message("Error initializing print mutex.", table);
	if (pthread_mutex_init(&table->end_simulation_mutex, NULL) != 0)
		error_message("Error initializing end_simulation mutex.", table);
	init_philo(table);
}

void	init_philo(t_table *table)
{
	t_philo	*philo;
	int		i;

	i = 0;
	while (i < table->philo_nbr)
	{
		philo = table->philo + i;
		philo->id = i + 1;
		philo->meals_counter = 0;
		philo->full = false;
		philo->last_meal_time = get_time();
		philo->table = table;
		if (pthread_mutex_init(&table->philo[i].meals_counter_mutex, NULL) != 0)
			error_message("Error initializing meals_counter mutex.", table);
		if (pthread_mutex_init(
				&table->philo[i].last_meal_time_mutex, NULL) != 0)
			error_message("Error initializing las_meal_time mutex.", table);
		if (pthread_mutex_init(&table->philo[i].full_mutex, NULL) != 0)
			error_message("Error initializing full mutex.", table);
		assign_forks(philo, table->fork, i);
		i++;
	}
}

void	assign_forks(t_philo *philo, t_fork *forks, int philo_position)
{
	int	philo_nbr;

	philo_nbr = philo->table->philo_nbr;
	philo->first_fork = &forks[(philo_position + 1) % philo_nbr];
	philo->second_fork = &forks[philo_position];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[philo_position];
		philo->second_fork = &forks[(philo_position + 1) % philo_nbr];
	}
}
