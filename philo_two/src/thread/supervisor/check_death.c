/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_death.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:24:15 by aberry            #+#    #+#             */
/*   Updated: 2021/04/13 14:32:10 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

int	ft_check_death(t_philosopher *philosopher)
{
	unsigned long		past_time;
	unsigned long		time_to_die;

	usleep(10);
	time_to_die = g_simulation.input_data->time_to_die + 5;
	past_time = ft_get_time_now(g_simulation.t_time) \
												- philosopher->time_last_eat;
	if (past_time >= time_to_die)
		return (1);
	return (0);
}
