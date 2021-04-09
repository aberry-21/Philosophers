/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   destroy_simulation.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:26:25 by aberry            #+#    #+#             */
/*   Updated: 2021/04/09 18:16:59 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

void	ft_destroy_simulation(t_simulation *simulation)
{
	int		counter;

	counter = 0;
	if (simulation->print_lock.__sig)
		pthread_mutex_destroy(&simulation->print_lock);
	if (simulation->forks)
	{
		while (counter < simulation->input_data->number_of_philo)
		{
			if (simulation->forks[counter].__sig)
				pthread_mutex_destroy(&simulation->forks[counter]);
			++counter;
		}
	}
	free(simulation->forks);
	free(simulation->input_data);
}
