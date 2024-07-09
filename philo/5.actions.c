/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:21:12 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/09 18:39:26 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void take_forks(t_philo *philo)
{
    t_table *table;
    
    table = get_table();
    if (table->end_simulation)
        return;
    pthread_mutex_lock(&philo->first_fork->fork);
    print_message(philo, P_FORK_ONE);
    pthread_mutex_lock(&philo->second_fork->fork);
    print_message(philo, P_FORK_TWO);
}

void    down_forks(t_philo *philo)
{
    t_table *table; 
    
    table = get_table();
    if (table->end_simulation)
        return;
    pthread_mutex_unlock(&philo->first_fork->fork);
    pthread_mutex_unlock(&philo->second_fork->fork);
}

void philo_sleep(t_philo *philo)
{
    t_table *table; 
    
    table = get_table();
    if (table->end_simulation)
        return;
    print_message(philo, SLEEP);
    usleep(table->time_to_sleep);
}

void    philo_eating(t_philo *philo)
{
    t_table *table;
    
    table = get_table();
    if (table->end_simulation)
        return;
    print_message(philo, EAT);
    philo->meals_counter++;
    usleep(table->time_to_eat);  
    down_forks(philo);
}

void philo_thinking(t_philo *philo)
{
    t_table *table; 
    
    table = get_table();
    if (table->end_simulation)
        return;
    print_message(philo, THINK);
    usleep(10000);
}
