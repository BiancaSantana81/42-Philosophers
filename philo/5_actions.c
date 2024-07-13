/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5_actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:21:12 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/13 20:22:23 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

static void	philo_eating_aux(t_philo *philo);

void	philo_eating(t_philo *philo)
{
	t_table	*table;

	table = get_table();
	if (is_philo_full(philo))
		return ;
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
	philo_eating_aux(philo);
}

static void	philo_eating_aux(t_philo *philo)
{
	t_table	*table;

	table = get_table();
	pthread_mutex_lock(&philo->last_meal_time_mutex);
	philo->last_meal_time = get_time();
	pthread_mutex_unlock(&philo->last_meal_time_mutex);
	pthread_mutex_lock(&philo->meals_counter_mutex);
	if (!philo->full)
	{
		philo->meals_counter++;
		print_message(philo, EAT);
		usleep(table->time_to_eat);
		down_forks(philo);
	}
	if (philo->meals_counter == table->nbr_limits_meals)
	{
		pthread_mutex_lock(&philo->full_mutex);
		philo->full = true;
		pthread_mutex_unlock(&philo->full_mutex);
	}
	pthread_mutex_unlock(&philo->meals_counter_mutex);
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

void	philo_thinking(t_philo *philo)
{
	t_table	*table;

	table = get_table();
	if (check_end_simulation(table))
		return ;
	print_message(philo, THINK);
	usleep(1000);
}
