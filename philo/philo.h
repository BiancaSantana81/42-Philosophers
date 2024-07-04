/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   philo.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/01 13:56:14 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/04 12:37:19 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PHILO_H
# define PHILO_H

/* LIBRARIES */
# include <stdio.h>
# include <unistd.h>
# include <stdlib.h>
# include <string.h>
# include <limits.h>
# include <pthread.h>
# include <sys/time.h>

#define RST "\033[0m"
#define RED "\033[1;31m"
#define WHITE "\033[1;37m"

void	error_message(char *string);
int     check_input(int argc, char **input);
int     ft_isdigit(int c);
int     is_number(char *input);
int     aux_check_input(int number, int argc, int i);
long int	ft_atol(const char *nptr);

#endif