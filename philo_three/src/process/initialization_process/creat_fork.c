/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   creat_fork.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:20:44 by aberry            #+#    #+#             */
/*   Updated: 2021/04/13 15:58:33 by aberry           ###   ########.fr       */
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
		{
			ft_create_supervisord_detach(ft_observation_of_philo, \
														&philosopher[counter]);
			ft_routina(&philosopher[counter]);
		}
		++counter;
	}
}
