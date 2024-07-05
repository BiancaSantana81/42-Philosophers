/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   trash.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42sp.org.br     +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/05 10:30:55 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/05 15:40:22 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "philo.h"

void    print_table(t_table *table)
{
    printf("Number of philosophers: %d\n", table->philo_nbr);
    printf("Time to die: %ld\n", table->time_to_die);
    printf("Time to eat: %ld\n", table->time_to_eat);
    printf("Time to sleep: %ld\n", table->time_to_sleep);
    printf("Number of meal limits: %ld\n", table->nbr_limits_mails);
   // printf("Start simulation: %ld\n", table->start_simulation);
    //printf("End simulation: %d\n", table->end_simulation);

    if(table->philos)
        printf("Memória dos philos alocada com sucesso\n.");
    if (table->forks)
     printf("Memória dos forks alocada com sucesso\n.");
}
