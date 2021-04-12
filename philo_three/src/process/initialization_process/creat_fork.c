/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_thread.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:20:44 by aberry            #+#    #+#             */
/*   Updated: 2021/04/09 18:20:50 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

void	ft_create_fork_philo(t_philosopher *philosopher, int size)
{
	int		counter;
	int		status;

	counter = 0;
	g_simulation.t_time = ft_get_time_now(0);
	while (counter < size)
	{
		status = fork();
		if (status == -1)
		{
			printf(ERR_FORK);
			ft_destroy_simulation(&g_simulation, FAIL);
		}
		if (status != 0)
			g_simulation.array_pid[counter] = status;
		else
			ft_routina(&philosopher[counter]);
		++counter;
	}
}
