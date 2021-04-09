/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:05:01 by aberry            #+#    #+#             */
/*   Updated: 2021/04/09 18:09:42 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include "input.h"
# include "time_t.h"

# define SUCCESS 0
# define FAIL 1
# define ERR_THREAD "Main error: can't create thread"
# define ERR_JOIN "Main error: can't start join"
# define ERR_DETACH "Main error: can't start detach"
# define ERR_MUTEX "Main error: can't create mutex"
# define TAKE_FORK " has taken a fork\n"
# define EATING " is eating\n"
# define SLEEPING " is sleeping\n"
# define THINKING " is thinking\n"
# define DYING " died\n"

typedef struct s_philosopher
{
	pthread_t		thread_philo;
	int				id;
	int				count_eat;
	unsigned long	time_last_eat;
	unsigned int	left_fork;
	unsigned int	right_fork;
}					t_philosopher;

typedef struct s_simulation
{
	t_data			*input_data;
	pthread_mutex_t	*forks;
	pthread_mutex_t	print_lock;
	unsigned long	t_time;
}					t_simulation;

t_simulation		g_simulation;

int					ft_init_simulation(t_simulation *simulation, int argc, \
															char const *argv[]);
t_philosopher		*ft_init_philosophers_for_simulation(int size);
pthread_mutex_t		*ft_init_table(int size);
void				*ft_routina(void *args);
int					ft_create_thread_philo(t_philosopher *philosopher, \
																	int size);
int					ft_detach_thread_philo(t_philosopher *philosopher, \
																	int size);
void				*ft_start_simulation(void *args);
int					ft_check_count_eat(t_philosopher *philosopher, int size);
int					ft_check_death(t_philosopher *philosopher);
void				ft_create_supervisord(void);
void				ft_observation_of_philo(t_philosopher *philosopher, \
																	int size);
void				ft_destroy_simulation(t_simulation *simulation);
void				ft_print_message(int id, char *message);

#endif
