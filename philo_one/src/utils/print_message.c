/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   print_message.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:26:41 by aberry            #+#    #+#             */
/*   Updated: 2021/04/13 14:18:21 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

void	ft_print_message(int id, char *message)
{
	pthread_mutex_lock(&g_simulation.print_lock);
	printf("\033[1;32m%lu\033[0m\t\033[1;36m%d\033[0m %s", \
						ft_get_time_now(g_simulation.t_time), id, message);
	pthread_mutex_unlock(&g_simulation.print_lock);
}
