/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:21:12 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/12 15:38:44 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	take_forks(t_philo *philo)
{
	t_table	*table;

	table = get_table();
	pthread_mutex_lock(&philo->first_fork->fork);
	if (check_end_simulation(table))
	{
		pthread_mutex_unlock(&philo->first_fork->fork);
		return ;
	}
	print_message(philo, P_FORK_ONE);
	pthread_mutex_lock(&philo->second_fork->fork);
	if (check_end_simulation(table))
	{
		pthread_mutex_unlock(&philo->first_fork->fork);
		pthread_mutex_unlock(&philo->second_fork->fork);
		return ;
	}
	print_message(philo, P_FORK_TWO);
}

void	down_forks(t_philo *philo)
{
	pthread_mutex_unlock(&philo->first_fork->fork);
	pthread_mutex_unlock(&philo->second_fork->fork);
}

void	philo_sleep(t_philo *philo)
{
	t_table	*table;

	table = get_table();
	if (check_end_simulation(table))
		return ;
	print_message(philo, SLEEP);
	usleep(table->time_to_sleep);
}

void	philo_eating(t_philo *philo)
{
	t_table	*table;

	table = get_table();
	if (check_end_simulation(table))
		return ;
	take_forks(philo);
	if (check_end_simulation(table))
	{
		down_forks(philo);
		return ;
	}
	pthread_mutex_lock(&philo->last_meal_time_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->last_meal_time_mutex);
	print_message(philo, EAT);
	pthread_mutex_lock(&philo->meals_counter_mutex);
	philo->meals_counter++;
	pthread_mutex_unlock(&philo->meals_counter_mutex);
	usleep(table->time_to_eat);
	down_forks(philo);
}

void	philo_thinking(t_philo *philo)
{
	t_table	*table;

	table = get_table();
	if (check_end_simulation(table))
		return ;
	print_message(philo, THINK);
	usleep(1000);
}
