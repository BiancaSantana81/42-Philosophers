/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: bsantana <bsantana@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/07/03 17:57:48 by bsantana          #+#    #+#             */
/*   Updated: 2024/07/04 16:19:38 by bsantana         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "philo.h"

void	error_message(char *string, t_table *table)
{
	printf(RED"🚨 "WHITE"%s"RED" 🚨\n"RST, string);
	free(table);
	exit(1);
}
