/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_simulation.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/06 21:47:44 by aberry            #+#    #+#             */
/*   Updated: 2021/04/13 15:09:26 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

static int	ft_sem_open(sem_t **semaphore, char *name, int amount)
{
	sem_unlink(name);
	*semaphore = sem_open(name, O_CREAT | O_EXCL, 0644, amount);
	if (*semaphore == SEM_FAILED)
	{
		printf(ERR_SEM);
		return (FAIL);
	}
	return (SUCCESS);
}

static int	ft_create_semaphore(t_simulation *simulation, int size_forks)
{
	int				status[4];
	int				counter;

	status[0] = ft_sem_open(&simulation->forks, FORKS_SEM, size_forks);
	status[1] = ft_sem_open(&simulation->print_lock, PRINT_SEM, 1);
	status[2] = ft_sem_open(&simulation->dead_philo, DEAD_SEM, 0);
	status[3] = ft_sem_open(&simulation->eat_philo, EAT_SEM, 0);
	counter = 0;
	while (counter < 4)
	{
		if (status[counter] != SUCCESS)
			return (FAIL);
		++counter;
	}
	return (SUCCESS);
}

static int	ft_init_field(t_simulation *simulation, int argc, \
															char const *argv[])
{
	simulation->input_data = ft_init_simulation_arg(argc, argv);
	if (simulation->input_data == 0)
		return (FAIL);
	simulation->array_pid = (int *)malloc(\
					simulation->input_data->number_of_philo * sizeof(int));
	if (simulation->array_pid == 0)
		return (FAIL);
	if (ft_create_semaphore(simulation, \
							simulation->input_data->number_of_philo) != SUCCESS)
		return (FAIL);
	return (SUCCESS);
}

int	ft_init_simulation(t_simulation *simulation, int argc, char const *argv[])
{
	int			status;

	memset((void *)simulation, 0, sizeof(t_simulation));
	status = ft_init_field(simulation, argc, argv);
	return (status);
}
