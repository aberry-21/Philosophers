/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:47:44 by aberry            #+#    #+#             */
/*   Updated: 2021/04/13 14:18:58 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

static int	ft_init_field(t_simulation *simulation, int argc, \
															char const *argv[])
{
	simulation->input_data = ft_init_simulation_arg(argc, argv);
	if (simulation->input_data == 0)
		return (FAIL);
	sem_unlink(FORKS_SEM);
	simulation->forks = sem_open(FORKS_SEM, O_CREAT | O_EXCL, 0644, \
							simulation->input_data->number_of_philo);
	if (simulation->forks == SEM_FAILED)
	{
		printf(ERR_SEM);
		return (FAIL);
	}
	sem_unlink(PRINT_SEM);
	simulation->print_lock = sem_open(PRINT_SEM, O_CREAT | O_EXCL, 0644, 1);
	if (simulation->print_lock == SEM_FAILED)
	{
		printf(ERR_SEM);
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
