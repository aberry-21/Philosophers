/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:26:25 by aberry            #+#    #+#             */
/*   Updated: 2021/04/13 14:19:14 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

static void	ft_destroy_fork(t_simulation *simulation)
{
	int		counter;

	counter = 0;
	if (simulation->forks)
	{
		while (counter < simulation->input_data->number_of_philo)
		{
			sem_post(simulation->forks);
			++counter;
		}
		sem_close(simulation->forks);
		sem_unlink(FORKS_SEM);
	}
}

void	ft_destroy_simulation(t_simulation *simulation)
{
	if (simulation->print_lock)
	{
		sem_post(simulation->print_lock);
		sem_close(simulation->print_lock);
		sem_unlink(PRINT_SEM);
	}
	ft_destroy_fork(simulation);
	free(simulation->input_data);
}
