/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_count_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:24:11 by aberry            #+#    #+#             */
/*   Updated: 2021/04/25 03:45:41 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

int	ft_check_count_eat(t_philosopher *philosopher, int size)
{
	int		counter;

	counter = 0;
	if (g_simulation.input_data->number_of_lunch == -1)
		return (1);
	while (counter < size)
	{
		if (philosopher[counter].count_eat !=\
									g_simulation.input_data->number_of_lunch)
			return (1);
		++counter;
	}
	return (0);
}
