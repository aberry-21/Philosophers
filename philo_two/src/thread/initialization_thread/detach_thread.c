/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   detach_thread.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:21:03 by aberry            #+#    #+#             */
/*   Updated: 2021/04/13 14:19:04 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

int	ft_detach_thread_philo(t_philosopher *philosopher, int size)
{
	int		counter;
	int		status;

	counter = 0;
	while (counter < size)
	{
		status = pthread_detach(philosopher[counter].thread_philo);
		if (status != SUCCESS)
		{
			printf(ERR_DETACH);
			return (FAIL);
		}
		++counter;
	}
	return (SUCCESS);
}
