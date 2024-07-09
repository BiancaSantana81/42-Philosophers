/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.2.routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:45:58 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/09 16:41:07 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *lonely_dinner(void)
{
    t_table table;

    table = *get_table();
    take_forks(table.philos);
    usleep(table.time_to_die);
    print_message(table.philos, DEATH);
    return (NULL);
}

void *routine(void *arg)
{
    t_philo *philo = (t_philo *)arg;
    t_table *table = philo->table;

    if (table->philo_nbr == 1)
        return (lonely_dinner());
    while (!(table->end_simulation))
    {
        take_forks(philo);
        philo_eating(philo);
        philo_sleep(philo);
        philo_thinking(philo);
    }
    return (NULL);
}
