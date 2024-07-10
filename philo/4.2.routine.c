/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.2.routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:45:58 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/10 20:44:09 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *lonely_dinner(void)
{
    t_table table;

    table = *get_table();
    printf("pobi vai morrer sozinho.\n");
    philo_eating(table.philo);
    usleep(table.time_to_die);
    down_forks(table.philo);
    print_message(table.philo, DEATH);
    return (NULL);
}

void *routine(void *arg)
{
    t_table table;
    t_philo *philo;

    table = *get_table();
    philo = (t_philo *)arg;
    if (table.philo_nbr == 1)
        return (lonely_dinner());
    pthread_mutex_lock(&table.end_simulation_mutex);
    while (!(table.end_simulation))
    {
        if (table.end_simulation == true)
            break ;
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
    pthread_mutex_unlock(&table.end_simulation_mutex);
    return (NULL);
}
