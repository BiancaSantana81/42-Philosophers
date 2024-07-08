/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.2.routine.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 16:45:58 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/08 18:50:09 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void lonely_dinner(void)
{
    printf("O pobi vai morrer sozinho :(\n");
    // lógica para apenas um filo -> ele deve morrer já que não terão garfos suficientes.
}

void *routine(void *arg)
{
    t_table *table;
   
    (void)table;
    table = (t_table *)arg;
    // if (table->philo_nbr == 1)
    //     lonely_dinner();
    // Enquanto não chegar o fim da simulação
        // Pensar
        // Pegar garfos
        // Comer
        // Soltar garfos
        // Dormir
        // repetir etapas anteriores... 
    return (NULL);
}
