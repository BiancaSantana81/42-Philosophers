/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.1.control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:46:50 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/10 21:48:51 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

bool	philo_satisfied(void)
{
	t_table	*table;
	int		i;

	i = 0;
	table = get_table();
	while (i < table->philo_nbr)
	{
		if (table->philo[i].meals_counter < table->nbr_limits_meals)
			return (false);
		i++;
	}
	return (true);
}

void	*philo_die(void *null)
{
	t_table	*table;

	(void)null;
	table = get_table();
	//pthread_mutex_lock(table->end_simulation);
	table->end_simulation = true;
    //pthread_mutex_unlock(table->end_simulation);
	print_message(table->philo, DEATH);
	return (NULL);
}

void	*control(void *null)
{
	t_table	*table;
	long	current_time;
	long	time_since_last_meal;
	int		i;

	(void)null;
	table = get_table();
	while (table->end_simulation == false)
	{
		i = 0;
		while (i < table->philo_nbr)
		{
			current_time = get_time();
			pthread_mutex_lock(&table->philo[i].last_meal_time_mutex);
			time_since_last_meal = (current_time - table->philo[i].last_meal_time) * 1000;
			if (time_since_last_meal > table->time_to_die)
			{
				print_message(&(table->philo[i]), DEATH);
				table->end_simulation = true;
				pthread_mutex_unlock(&table->philo[i].last_meal_time_mutex);
				return (NULL);
			}
			pthread_mutex_unlock(&table->philo[i].last_meal_time_mutex);
			i++;
		}
		if (table->nbr_limits_meals > 0 && philo_satisfied())
		{
			printf("Philosopher satisfied.\n");
			table->end_simulation = true;
			return (NULL);
		}
		usleep(500000);
	}
	return (NULL);
}
