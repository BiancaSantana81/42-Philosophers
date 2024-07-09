/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.1.control.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/08 15:46:50 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/09 14:30:02 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void *control(void *null)
{   
    (void)null;
    t_table table;
    //t_philo *philo;
    int     i;

    table = *get_table();
    //philo = table.philos;
    i = 0;
    while (i < table.philo_nbr)
    {
        if (table.time_to_die == 2000000)
        i++;
    }
    return (NULL);
}
