/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:57:48 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/10 14:09:07 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_message(char *string, t_table *table)
{
	printf("🚨 "RED"%s"RST" 🚨\n", string);
	free_everything(table);
	exit(1);
}

void	*allocate_memory(int bytes)
{
	void	*memory;

	memory = malloc(bytes);
	if (!memory)
		return (NULL);
	return (memory);
}

void free_everything(t_table *table)
{
	if (table->philo)
		free(table->philo);
	if (table->fork)
		free(table->fork);
	if (table)
		free(table);
}

t_table *get_table(void)
{
    static t_table table;
    return (&table);
}

void set_table(t_table *new_table)
{
    t_table *table = get_table();
    *table = *new_table;
}

void print_message(t_philo *philo, const char *message)
{
    t_table *table = philo->table;
	
	if (table->end_simulation)
        return;
    pthread_mutex_lock(&table->print);
    printf(message,get_elapsed_time(table->start_time), philo->id);
    pthread_mutex_unlock(&table->print);
}
