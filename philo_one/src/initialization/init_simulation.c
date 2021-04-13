/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:47:44 by aberry            #+#    #+#             */
/*   Updated: 2021/04/13 14:18:10 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

static int	ft_init_field(t_simulation *simulation, int argc, \
															char const *argv[])
{
	int			status;

	simulation->input_data = ft_init_simulation_arg(argc, argv);
	if (simulation->input_data == 0)
		return (FAIL);
	simulation->forks = ft_init_table(simulation->input_data->number_of_philo);
	if (simulation->forks == 0)
		return (FAIL);
	status = pthread_mutex_init(&simulation->print_lock, NULL);
	if (status != SUCCESS)
	{
		printf(ERR_MUTEX);
		return (FAIL);
	}
	return (SUCCESS);
}

int	ft_init_simulation(t_simulation *simulation, int argc, char const *argv[])
{
	int			status;

	memset((void *)simulation, 0, sizeof(t_simulation));
	status = ft_init_field(simulation, argc, argv);
	return (status);
}
