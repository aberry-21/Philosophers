/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create_join.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:22:28 by aberry            #+#    #+#             */
/*   Updated: 2021/04/13 14:18:46 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

void	ft_create_supervisord_join(void *(*start_routine)(void *), void *arg)
{
	int			status;
	pthread_t	supervisord_thread;

	status = pthread_create(&supervisord_thread, NULL, start_routine, arg);
	if (status != SUCCESS)
	{
		printf(ERR_THREAD);
		return ;
	}
	status = pthread_join(supervisord_thread, 0);
	if (status != SUCCESS)
	{
		printf(ERR_JOIN);
		return ;
	}
}
