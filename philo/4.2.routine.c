/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.2.routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:45:58 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/10 15:28:18 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *lonely_dinner(void)
{
    t_table table;

    table = *get_table();
    take_forks(table.philo);
    usleep(table.time_to_die);
    print_message(table.philo, DEATH);
    return (NULL);
}

void *routine(void *arg)
{
    t_table table;
    t_philo *philo;

    table = *get_table();
    philo = (t_philo *)arg;
    if (table.end_simulation == 1)
        return (lonely_dinner());
    while (!(table.end_simulation))
    {
        philo_eating(philo);
        if (table.end_simulation == true)
            break ;
        philo_sleep(philo);
        if (table.end_simulation == true)
            break ;
        philo_thinking(philo);
        if (table.end_simulation == true)
            break ;
    }
    return (NULL);
}
