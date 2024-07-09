/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.1.control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:46:50 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/09 19:05:32 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void philo_satisfied(void)
{
    t_table *table;
    int i;

    table = get_table();
    i = 0;
    while (i < table->philo_nbr)
    {
        if (table->philos[i].meals_counter < table->nbr_limits_mails)
            return;
        i++;
    }
    table->end_simulation = true;
}

void    *philo_die(void *null)
{
    (void)null;
    t_table *table;

    table = get_table();
    //pthread_mutex_lock(table->end_simulation);
    table->end_simulation = true;
    //pthread_mutex_unlock(table->end_simulation);
    print_message(table->philos, DEATH);
    return (NULL);
}

void *control(void *null)
{   
    (void)null;
    t_table *table;
    //t_philo *philo;
    int     i;

    table = get_table();
    //philo = table.philos;
    i = -1;
    while (table->end_simulation == false)
    {
        while (i++ < table->philo_nbr)
        {
            if (table->nbr_limits_mails > 0)
                philo_satisfied();
        }    
    }
    return (NULL);
}
