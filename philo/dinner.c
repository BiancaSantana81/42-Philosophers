// /* ************************************************************************** */
// /*                                                                            */
// /*                                                        :::      ::::::::   */
// /*   dinner.c                                           :+:      :+:    :+:   */
// /*                                                    +:+ +:+         +:+     */
// /*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
// /*                                                +#+#+#+#+#+   +#+           */
// /*   Created: 2024/07/07 17:08:02 by bsantana          #+#    #+#             */
// /*   Updated: 2024/07/08 13:01:19 by bsantana         ###   ########.fr       */
// /*                                                                            */
// /* ************************************************************************** */

#include "philo.h"

void *control(void *null)
{
    (void)null;
    return (NULL);
}

void *routine(void *arg)
{
    t_philo *philo;
   
    philo = (t_philo *)arg;
    printf("HELLO PHILO: %d THREAD_ID: %ld\n", philo->id, philo->thread_id);
    return (NULL);
}

void    dinner_start(t_table *table)
{
    int         i;
    int         j;
    pthread_t   controller;

    i = 0;
    j = 0;
    gettimeofday(&table->start_time, NULL);
    if (table->nbr_limits_mails == 0)
        return ;
    while (i < table->philo_nbr)
    {
        if (pthread_create(&table->philos[i].thread_id, NULL, routine, &table->philos[i]) != 0)
            error_message("Error creating thread.", table);
        i++;
    }
    if (table->philo_nbr > 1)
    {
        if (pthread_create(&controller, NULL, control, NULL) != 0)
            error_message("Error creating thread.", table);
    }
    while (j < table->philo_nbr)
    {
        if (pthread_join(table->philos[j].thread_id, NULL) != 0)
            error_message("Error join thread.", table);
        j++;
    }
    if (table->philo_nbr > 1)
    {
        if (pthread_join(controller, NULL) != 0)
            error_message("Error join thread.", table);
    }
}
