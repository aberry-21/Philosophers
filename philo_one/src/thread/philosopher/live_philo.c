/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   live_philo.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/09 17:07:37 by aberry            #+#    #+#             */
/*   Updated: 2021/04/09 18:20:04 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

static void	ft_eating_philo(pthread_mutex_t *forks, \
													t_philosopher *philosopher)
{
	pthread_mutex_lock(&forks[philosopher->left_fork]);
	ft_print_message(philosopher->id, TAKE_FORK);
	pthread_mutex_lock(&forks[philosopher->right_fork]);
	ft_print_message(philosopher->id, TAKE_FORK);
	ft_msleep(g_simulation.input_data->time_to_eat);
	ft_print_message(philosopher->id, EATING);
	philosopher->time_last_eat = ft_get_time_now(g_simulation.t_time);
	++philosopher->count_eat;
	pthread_mutex_unlock(&forks[philosopher->right_fork]);
	pthread_mutex_unlock(&forks[philosopher->left_fork]);
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
	pthread_mutex_t	*forks;

	philosopher = (t_philosopher *)args;
	forks = g_simulation.forks;
	if (philosopher->id % 2)
		ft_msleep(60);
	while (1)
	{
		ft_eating_philo(forks, philosopher);
		if (g_simulation.input_data->number_of_lunch != -1 &&\
			g_simulation.input_data->number_of_lunch <= philosopher->count_eat)
			break ;
		ft_another_action_philo(philosopher);
	}
	return ((void *)SUCCESS);
}
