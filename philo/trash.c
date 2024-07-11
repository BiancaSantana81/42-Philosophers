/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:30:55 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/11 15:40:28 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    print_table(t_table *table)
{
    int i = 0;
    
    printf("Number of philosophers: %d\n", table->philo_nbr);
    printf("Time to die: %ld\n", table->time_to_die);
    printf("Time to eat: %ld\n", table->time_to_eat);
    printf("Time to sleep: %ld\n", table->time_to_sleep);
    printf("Number of meal limits: %ld\n", table->nbr_limits_meals);
    
    while (i < table->philo_nbr)
    {
        printf("Philosopher ID = %d\n", table->philo[i].id);
        i++;
    }
    if (table->philo)
        printf("Memory for philosophers allocated successfully.\n");
    
    if (table->fork)
        printf("Memory for forks allocated successfully.\n");
}

