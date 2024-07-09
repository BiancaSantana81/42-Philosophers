/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   4.3.time.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 17:05:38 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/09 17:05:55 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

long get_time()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000) + (tv.tv_usec / 1000);
}

long get_elapsed_time(long start_time)
{
    return get_time() - start_time;
}
