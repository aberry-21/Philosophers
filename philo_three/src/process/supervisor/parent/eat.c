/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   eat.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:24:03 by aberry            #+#    #+#             */
/*   Updated: 2021/04/13 14:18:44 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

void	*ft_supervisor_of_philo_eat(void *args)
{
	int		counter_eat;
	int		counter;

	(void)args;
	counter_eat = g_simulation.input_data->number_of_philo;
	counter = 0;
	while (counter != counter_eat)
	{
		sem_wait(g_simulation.eat_philo);
		++counter;
	}
	sem_wait(g_simulation.print_lock);
	ft_destroy_simulation(&g_simulation, SUCCESS);
	return (SUCCESS);
}
