/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   5.actions.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/09 11:21:12 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/09 11:47:02 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void    take_forks(t_philo *philo)
{
    pthread_mutex_lock(&philo->first_fork->fork);
    printf(P_FORK_ONE, philo->thread_id, philo->id);
    pthread_mutex_lock(&philo->first_fork->fork);
    printf(P_FORK_TWO, philo->thread_id, philo->id);
}

void    down_forks(t_philo *philo)
{
    pthread_mutex_unlock(&philo->first_fork->fork);
    printf(D_FORK_ONE, philo->thread_id, philo->id);
    pthread_mutex_unlock(&philo->first_fork->fork);
    printf(D_FORK_TWO, philo->thread_id, philo->id);
}
