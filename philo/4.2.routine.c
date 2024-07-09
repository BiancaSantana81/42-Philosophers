/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.2.routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:45:58 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/09 15:12:12 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    *lonely_dinner(void)
{
    t_table table;

    table = *get_table();
    take_forks(table.philos);
    usleep(table.time_to_die);
    printf(DEATH, table.philos->thread_id, table.philos->id);
    return (NULL);
}

void *routine(void *arg)
{
    t_table table;

    (void)arg;
    table = *get_table();
    if (table.philo_nbr == 1)
        return(lonely_dinner());
    while (!(table.end_simulation))
    {
        philo_sleep(table.philos);
        take_forks(table.philos);
    }
    return (NULL);
}

