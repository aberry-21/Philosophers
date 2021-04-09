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

void	ft_create_supervisord(void)
{
	int			status;
	pthread_t	supervisord_thread;

	status = pthread_create(&supervisord_thread, NULL, ft_start_simulation, 0);
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
