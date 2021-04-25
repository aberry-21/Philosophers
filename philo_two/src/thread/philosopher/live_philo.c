/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:07:37 by aberry            #+#    #+#             */
/*   Updated: 2021/04/25 04:02:03 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

static void	ft_eating_philo(t_philosopher *philosopher)
{
	sem_wait(g_simulation.forks);
	ft_print_message(philosopher->id, TAKE_FORK);
	sem_wait(g_simulation.forks);
	ft_print_message(philosopher->id, TAKE_FORK);
	ft_print_message(philosopher->id, EATING);
	++philosopher->count_eat;
	philosopher->time_last_eat = ft_get_time_now(g_simulation.t_time);
	ft_msleep(g_simulation.input_data->time_to_eat);
	sem_post(g_simulation.forks);
	sem_post(g_simulation.forks);
}

static void	ft_another_action_philo(t_philosopher *philosopher)
{
	ft_print_message(philosopher->id, SLEEPING);
	ft_msleep(g_simulation.input_data->time_to_sleep);
	ft_print_message(philosopher->id, THINKING);
}

void	*ft_routina(void *args)
{
	t_philosopher	*philosopher;

	philosopher = (t_philosopher *)args;
	if (philosopher->id % 2)
		ft_msleep(60);
	while (g_simulation.dead_philo != 1)
	{
		ft_eating_philo(philosopher);
		if (g_simulation.dead_philo || \
			(g_simulation.input_data->number_of_lunch != -1 && \
			g_simulation.input_data->number_of_lunch <= philosopher->count_eat))
			break ;
		ft_another_action_philo(philosopher);
	}
	return ((void *)SUCCESS);
}
