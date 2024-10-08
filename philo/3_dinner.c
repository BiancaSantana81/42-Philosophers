/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   3_dinner.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/10 21:15:31 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/15 13:38:11 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	create_threads(t_table *table);
static void	join_thread(t_table *table);

static void	create_threads(t_table *table)
{
	int	i;

	i = 0;
	while (i < table->philo_nbr)
	{
		if (pthread_create(&table->philo[i].thread_id,
				NULL, routine, (void *)&table->philo[i]) != 0)
			error_message("Error creating thread.", table);
		i++;
	}
}

static void	join_thread(t_table *table)
{
	int	j;

	j = 0;
	while (j < table->philo_nbr)
	{
		if (pthread_join(table->philo[j].thread_id, NULL) != 0)
			error_message("Error join thread.", table);
		j++;
	}
}

void	dinner_start(t_table *table)
{
	pthread_t	controller;

	table->start_time = get_time();
	if (table->nbr_limits_meals == 0)
		return ;
	create_threads(table);
	if (table->philo_nbr > 1)
	{
		if (pthread_create(&controller, NULL, control, NULL) != 0)
			error_message("Error creating thread.", table);
	}
	join_thread(table);
	if (table->philo_nbr > 1)
	{
		if (pthread_join(controller, NULL) != 0)
			error_message("Error join thread.", table);
	}
	destroy_mutexes(table);
}
