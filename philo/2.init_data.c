/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   2.init_data.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 11:27:18 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/09 15:30:40 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void data_init(t_table *table)
{
    int i;

    i = 0;
    table->end_simulation = false;
    table->philos = allocate_memory(sizeof(t_philo) * table->philo_nbr);
    table->forks = allocate_memory(sizeof(t_fork) * table->philo_nbr);
    while (i < table->philo_nbr)
    {
        if (pthread_mutex_init(&table->forks[i].fork, NULL) != 0)
			error_message("Error initializing mutex.", table);
        table->forks[i].id = i;
        i++;
    }
	if (pthread_mutex_init(&table->print, NULL) != 0)
        error_message("Error initializing print mutex.", table);
    init_philo(table);
}

void	init_philo(t_table *table)
{
	t_philo	*philo;
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		philo = table->philos + i;
		philo->id = i + 1;
		philo->full = false;
		philo->meals_counter = 0;
		philo->table = table;
		assign_forks(philo, table->forks, i);
		i++;
	}
}

void assign_forks(t_philo *philo, t_fork *forks, int philo_position)
{
	int philo_nbr;
	
	philo_nbr = philo->table->philo_nbr;
	philo->first_fork = &forks[(philo_position + 1) % philo_nbr];
	philo->second_fork = &forks[philo_position];
	if (philo->id % 2 == 0)
	{
		philo->first_fork = &forks[philo_position];
		philo->second_fork = &forks[(philo_position + 1) % philo_nbr];	
	}
}
