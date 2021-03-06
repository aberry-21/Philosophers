/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   observation_of_philo.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:24:03 by aberry            #+#    #+#             */
/*   Updated: 2021/04/25 04:03:47 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

void	ft_observation_of_philo(t_philosopher *philosopher, int size)
{
	int		counter;

	while (size)
	{
		counter = 0;
		while (counter < size)
		{
			if (ft_check_count_eat(philosopher, size) == 0)
			{
				sem_wait(g_simulation.print_lock);
				return ;
			}
			if (ft_check_death(&philosopher[counter]))
			{
				sem_wait(g_simulation.print_lock);
				printf("\033[1;32m%lu\033[0m\t\033[1;36m%d\033[0m %s", \
										ft_get_time_now(g_simulation.t_time), \
										philosopher[counter].id, DYING);
				++g_simulation.dead_philo;
				return ;
			}
			++counter;
		}
	}
}
