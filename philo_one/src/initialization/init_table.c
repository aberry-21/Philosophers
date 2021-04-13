/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_table.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:47:10 by aberry            #+#    #+#             */
/*   Updated: 2021/04/13 14:18:12 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

pthread_mutex_t	*ft_init_table(int size)
{
	int				counter;
	int				status;
	pthread_mutex_t	*forks;

	counter = 0;
	forks = (pthread_mutex_t *)malloc(size * sizeof(pthread_mutex_t));
	if (forks == 0)
		return ((pthread_mutex_t *)0);
	while (counter < size)
	{
		status = pthread_mutex_init(&forks[counter], NULL);
		if (status != SUCCESS)
		{
			printf(ERR_MUTEX);
			return ((pthread_mutex_t *)0);
		}
		++counter;
	}
	return (forks);
}
