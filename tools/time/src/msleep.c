/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   msleep.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 19:05:29 by aberry            #+#    #+#             */
/*   Updated: 2021/04/09 18:23:42 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_t.h"

int	ft_msleep(useconds_t time)
{
	unsigned long	current_time;
	unsigned long	required_time;

	current_time = ft_gettimeofday();
	required_time = current_time + time;
	while (current_time <= required_time)
	{
		if (usleep(10) == 1)
			return (1);
		current_time = ft_gettimeofday();
	}
	return (0);
}
