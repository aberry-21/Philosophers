/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:18:32 by aberry            #+#    #+#             */
/*   Updated: 2021/04/09 18:17:30 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

void	*ft_start_simulation(void *args)
{
	t_philosopher	*philosopher;
	int				size_philo;

	(void)args;
	size_philo = g_simulation.input_data->number_of_philo;
	philosopher = ft_init_philosophers_for_simulation(size_philo);
	if (philosopher == 0)
		return ((void *)FAIL);
	if (ft_create_thread_philo(philosopher, size_philo) != SUCCESS)
	{
		free(philosopher);
		return ((void *)FAIL);
	}
	if (ft_detach_thread_philo(philosopher, size_philo) != SUCCESS)
	{
		free(philosopher);
		return ((void *)FAIL);
	}
	ft_observation_of_philo(philosopher, size_philo);
	return ((void *)SUCCESS);
}
