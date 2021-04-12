/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:22:28 by aberry            #+#    #+#             */
/*   Updated: 2021/04/09 18:19:01 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"


void	ft_create_supervisord_detach(void *(*start_routine)(void *), void *arg)
{
	int			status;
	pthread_t	supervisord_thread;

	status = pthread_create(&supervisord_thread, NULL, start_routine, arg);
	if (status != SUCCESS)
	{
		printf(ERR_THREAD);
		return ;
	}
	status = pthread_detach(supervisord_thread);
	if (status != SUCCESS)
	{
		printf(ERR_DETACH);
		return ;
	}
}