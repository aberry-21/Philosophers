/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   start_simulation.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:18:32 by aberry            #+#    #+#             */
/*   Updated: 2021/04/13 15:36:33 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

void	ft_start_simulation(void)
{
	t_philosopher	*philosopher;
	int				size_philo;

	size_philo = g_simulation.input_data->number_of_philo;
	if (size_philo == 0)
		return ;
	philosopher = ft_init_philosophers_for_simulation(size_philo);
	if (philosopher == 0)
		return ;
	ft_create_supervisord_detach(ft_supervisor_of_philo_eat, 0);
	ft_create_fork_philo(philosopher, size_philo);
	ft_create_supervisord_join(ft_supervisor_of_philo_dead, 0);
}
