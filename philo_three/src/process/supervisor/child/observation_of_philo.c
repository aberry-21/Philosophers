/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:24:15 by aberry            #+#    #+#             */
/*   Updated: 2021/04/09 18:18:49 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

void	*ft_observation_of_philo(void *args)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)args;
	while (1)
	{
		if (ft_check_count_eat(philosopher) == 0)
		{
			sem_post(g_simulation.eat_philo);
			break ;
		}
		if (ft_check_death(philosopher))
		{
			sem_wait(g_simulation.print_lock);
			printf("\033[1;32m%lu\033[0m\t\033[1;36m%d\033[0m %s", \
									ft_get_time_now(g_simulation.t_time), \
									philosopher->id, DYING);
			sem_post(g_simulation.dead_philo);
			break ;
		}
	}
	exit(0);
}