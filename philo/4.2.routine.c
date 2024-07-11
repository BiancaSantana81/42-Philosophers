/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.2.routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:45:58 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/11 16:08:48 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static bool	check_end_simulation(t_table *table);
static void	philo_actions(t_philo *philo);

void	*lonely_dinner(void)
{
	t_table	*table;

	table = get_table();
	print_message(table->philo, P_FORK_ONE);
	pthread_mutex_lock(&table->end_simulation_mutex);
	table->end_simulation = true;
	pthread_mutex_unlock(&table->end_simulation_mutex);
	usleep(table->time_to_die);
	print_message(table->philo, DIE_ALONE);
	return (NULL);
}

void	*routine(void *arg)
{
	t_table	*table;
	t_philo	*philo;

	table = get_table();
	philo = (t_philo *)arg;
	if (table->philo_nbr == 1)
		return (lonely_dinner());
	while (!check_end_simulation(table))
		philo_actions(philo);
	return (NULL);
}

static bool	check_end_simulation(t_table *table)
{
	bool	end_simulation;

	pthread_mutex_lock(&table->end_simulation_mutex);
	end_simulation = table->end_simulation;
	pthread_mutex_unlock(&table->end_simulation_mutex);
	return (end_simulation);
}

static void	philo_actions(t_philo *philo)
{
	t_table	*table;

	table = get_table();
	philo_eating(philo);
	if (check_end_simulation(table))
		return ;
	philo_sleep(philo);
	if (check_end_simulation(table))
		return ;
	philo_thinking(philo);
}
