/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_philosophers.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:46:21 by aberry            #+#    #+#             */
/*   Updated: 2021/04/09 18:21:29 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

static void	ft_init_philosopher(t_philosopher *philosopher, int id)
{
	philosopher->count_eat = 0;
	philosopher->time_last_eat = 0;
	philosopher->id = id;
}

t_philosopher	*ft_init_philosophers_for_simulation(int size)
{
	t_philosopher	*philosopher;
	int				counter;

	philosopher = (t_philosopher *)malloc(size * sizeof(t_philosopher));
	if (philosopher == 0)
		return ((t_philosopher *)0);
	counter = 0;
	while (counter < size)
	{
		ft_init_philosopher(&philosopher[counter], counter + 1);
		++counter;
	}
	return (philosopher);
}
