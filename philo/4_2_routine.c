/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4_2_routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:45:58 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/15 13:51:11 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_actions(t_philo *philo);

bool	is_philo_full(t_philo *philo)
{
	bool	full;

	pthread_mutex_lock(&philo->full_mutex);
	full = philo->full;
	pthread_mutex_unlock(&philo->full_mutex);
	return (full);
}

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
	t_philo	*philo;
	t_table	*table;

	philo = (t_philo *)arg;
	table = get_table();
	if (table->philo_nbr == 1)
		return (lonely_dinner());
	while (!check_end_simulation(table))
		philo_actions(philo);
	return (NULL);
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
