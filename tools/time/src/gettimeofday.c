/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   gettimeofday.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 22:06:23 by aberry            #+#    #+#             */
/*   Updated: 2021/04/09 18:23:16 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_t.h"

unsigned long	ft_gettimeofday(void)
{
	struct timeval	current_time;

	gettimeofday(&current_time, NULL);
	return ((current_time.tv_sec) * 1000 + (current_time.tv_usec) / 1000);
}
