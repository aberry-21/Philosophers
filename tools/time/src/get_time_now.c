/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_time_now.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/08 23:40:48 by aberry            #+#    #+#             */
/*   Updated: 2021/04/09 18:23:12 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "time_t.h"

unsigned long	ft_get_time_now(unsigned long t_time)
{
	return (ft_gettimeofday() - t_time);
}
