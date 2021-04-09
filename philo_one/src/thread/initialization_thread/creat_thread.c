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

int	ft_create_thread_philo(t_philosopher *philosopher, int size)
{
	int		counter;
	int		status;

	counter = 0;
	g_simulation.t_time = ft_get_time_now(0);
	while (counter < size)
	{
		status = pthread_create(&philosopher[counter].thread_philo, \
									NULL, ft_routina, &philosopher[counter]);
		if (status != SUCCESS)
		{
			ft_detach_thread_philo(philosopher, counter);
			printf(ERR_THREAD);
			return (FAIL);
		}
		++counter;
	}
	return (SUCCESS);
}
