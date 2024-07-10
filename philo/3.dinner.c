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

static void     create_threads(t_table *table);
static void     join_thread(t_table *table);
static void     destroy_mutexes(t_table *table);

static void    create_threads(t_table *table)
{
    int i;
    
    i = 0;
    while (i < table->philo_nbr)
    {
        if (pthread_create(&table->philo[i].thread_id, NULL, routine, (void *)&table->philo[i]) != 0)
            error_message("Error creating thread.", table);
        i++;
    }
}

static void join_thread(t_table *table)
{
    int j;

    j = 0;
    while (j < table->philo_nbr)
    {
        if (pthread_join(table->philo[j].thread_id, NULL) != 0)
            error_message("Error join thread.", table);
        j++;
    }
}

static void destroy_mutexes(t_table *table)
{
    int i;
    int j;

    i = 0;
    j = 0;
    if (pthread_mutex_destroy(&table->print) != 0)
        error_message("Error destroying print mutex.", table);
    if (pthread_mutex_destroy(&table->end_simulation_mutex) != 0)
        error_message("Error destroying end mutex.", table);
    while (i < table->philo_nbr)
    {
        if (pthread_mutex_destroy(&table->fork[i].fork) != 0)
			error_message("Error destroying fork mutex.", table);
        i++;
    }
    while (j < table->philo_nbr)
    {
        if (pthread_mutex_destroy(&table->philo[j].meals_counter_mutex) != 0)
            error_message("Error destroying meals_counter.", table);
        else if (pthread_mutex_destroy(&table->philo[j].last_meal_time_mutex) != 0)
            error_message("Error destroying last_meal_time.", table);
        j++;
    }
}
void    dinner_start(t_table *table)
{
    pthread_t   controller;

    table->start_time = get_time();
    if (table->nbr_limits_meals == 0)
        return ;
    create_threads(table);
    if (table->philo_nbr > 1)
    {
        if (pthread_create(&controller, NULL, control, NULL) != 0)
            error_message("Error creating thread.", table);
    }
    join_thread(table);
    if (table->philo_nbr > 1)
    {
        if (pthread_join(controller, NULL) != 0)
            error_message("Error join thread.", table);
    }
    destroy_mutexes(table);
}
