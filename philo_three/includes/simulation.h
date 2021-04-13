/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   simulation.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:05:01 by aberry            #+#    #+#             */
/*   Updated: 2021/04/13 14:18:27 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SIMULATION_H
# define SIMULATION_H

# include <pthread.h>
# include <stdlib.h>
# include <stdio.h>
# include <string.h>
# include <semaphore.h>
# include "input.h"
# include "time_t.h"

# define SUCCESS 0
# define FAIL 1
# define ERR_THREAD "Main error: can't create process\n"
# define ERR_JOIN "Main error: can't start join\n"
# define ERR_FORK "Main error: can't start fork\n"
# define ERR_DETACH "Main error: can't start detach\n"
# define ERR_SEM "Main error: can't open semaphore\n"

# define FORKS_SEM "forks_sem"
# define PRINT_SEM "print_sem"
# define DEAD_SEM "dead_sem"
# define EAT_SEM "eat_sem"

# define TAKE_FORK " has taken a fork\n"
# define EATING " is eating\n"
# define SLEEPING " is sleeping\n"
# define THINKING " is thinking\n"
# define DYING " died\n"

typedef struct s_philosopher
{
	int				id;
	int				count_eat;
	unsigned long	time_last_eat;
}					t_philosopher;

typedef struct s_simulation
{
	t_data			*input_data;
	int				*array_pid;
	sem_t			*forks;
	sem_t			*print_lock;
	sem_t			*dead_philo;
	sem_t			*eat_philo;
	unsigned long	t_time;
}					t_simulation;

t_simulation		g_simulation;

/*
********************************************************************************
*/

/*
** Инициализация глобальной структуры g_simulation
*/
int					ft_init_simulation(t_simulation *simulation, int argc, \
															char const *argv[]);

/*
** Инициализация философов
*/
t_philosopher		*ft_init_philosophers_for_simulation(int size);

/*
** Жизнь философов (едят, спят, думают)
*/
void				*ft_routina(void *args);

/*
** Создание процессов филосовоф
*/
void				ft_create_fork_philo(t_philosopher *philosopher, \
																	int size);

/*
** Начало симуляции
*/
void				ft_start_simulation(void);

/*
** Создание потока, отделенного от главного потока
*/
void				ft_create_supervisord_detach( \
									void *(*start_routine)(void *), void *arg);

/*
** Создание потока, главный поток ожидает дочерний
*/
void				ft_create_supervisord_join(void *(*start_routine)(void *), \
																	void *arg);

/*
** Главный поток ждет освобождения семафора, на то что все поели
*/
void				*ft_supervisor_of_philo_eat(void *args);

/*
** Главный поток ждет освобождения семафора, на то что кто то умер
*/
void				*ft_supervisor_of_philo_dead(void *args);

/*
** В каждом отдельном процессе создается отдельный поток наблюдающий
** за философом
*/
void				*ft_observation_of_philo(void *args);

/*
** Супервизор философа проверяет сколько раз он поел
*/
int					ft_check_count_eat(t_philosopher *philosopher);

/*
** Супервизор философа проверяет умер ли он
*/
int					ft_check_death(t_philosopher *philosopher);

/*
** Деструктор симуляции
*/
void				ft_destroy_simulation(t_simulation *simulation, int status);

/*
** Вывод сообщения в 1 дескриптор
*/
void				ft_print_message(int id, char *message);

/*
********************************************************************************
*/

#endif
