/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:21:12 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/09 16:36:27 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void take_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->first_fork->fork);
    print_message(philo, P_FORK_ONE);
    pthread_mutex_lock(&philo->second_fork->fork);
    print_message(philo, P_FORK_TWO);
}

void    down_forks(t_philo *philo)
{
    pthread_mutex_unlock(&philo->first_fork->fork);
    print_message(philo, D_FORK_ONE);
    pthread_mutex_unlock(&philo->second_fork->fork);
    print_message(philo, D_FORK_TWO);
}

void philo_sleep(t_philo *philo)
{
    t_table *table = philo->table;

    print_message(philo, SLEEP);
    usleep(table->time_to_sleep);
}

void    philo_eating(t_philo *philo)
{
    t_table *table = philo->table;

    if (!table->end_simulation)
    {
        print_message(philo, EAT);
        philo->meals_counter++;   
        down_forks(philo);
    }
}

void philo_thinking(t_philo *philo)
{
    print_message(philo, THINK);
    usleep(10000); // Simular o tempo de pensar
}
