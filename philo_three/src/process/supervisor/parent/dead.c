/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   dead.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:24:03 by aberry            #+#    #+#             */
/*   Updated: 2021/04/13 14:18:43 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

void	*ft_supervisor_of_philo_dead(void *args)
{
	(void)args;
	sem_wait(g_simulation.dead_philo);
	ft_destroy_simulation(&g_simulation, SUCCESS);
	return (SUCCESS);
}
