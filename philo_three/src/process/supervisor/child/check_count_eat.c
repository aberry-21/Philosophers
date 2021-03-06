/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_count_eat.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:24:11 by aberry            #+#    #+#             */
/*   Updated: 2021/04/13 14:18:40 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

int	ft_check_count_eat(t_philosopher *philosopher)
{
	if (philosopher->count_eat != g_simulation.input_data->number_of_lunch)
		return (1);
	return (0);
}
