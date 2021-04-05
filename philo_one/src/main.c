/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:55:29 by aberry            #+#    #+#             */
/*   Updated: 2021/04/05 22:52:19 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"
#include <pthread.h>

int		main(int argc, char const *argv[])
{
	
	pthread_t	thread_1;
	pthread_t	thread_2;
	pthread_t	thread_3;
	t_data		*input_data;

	input_data = ft_init_simulation_arg(argc, argv);
	if (input_data == 0)
		return (0);
	printf("number_of_philo = %d\n", input_data->number_of_philo);
	printf("time_to_die = %d\n", input_data->time_to_die);
	printf("time_to_eat = %d\n", input_data->time_to_eat);
	printf("time_to_sleep = %d\n", input_data->time_to_sleep);
	printf("number_of_lunch = %d\n", input_data->number_of_lunch);
	return (0);
}

// #include <stdio.h>
// #include <stdlib.h>
// #include <pthread.h>
 
// static int counter = 0;
 
// typedef struct use_mutex_tag
// {
//     pthread_mutex_t mutex;
// } use_mutex_t;
 
// void* minus(void *args) {
//     int local;
//     use_mutex_t *arg = (use_mutex_t*) args;
//     pthread_mutex_lock(&(arg->mutex));
//     local = counter;
//     printf("min %d\n", counter);
//     local = local - 1;
//     counter = local;
//     pthread_mutex_unlock(&(arg->mutex));
//     return NULL;
// }
 
// void* plus(void *args)
// {
//     int local;
//     use_mutex_t *arg = (use_mutex_t*) args;
//     pthread_mutex_lock(&(arg->mutex));
//     local = counter;
//     printf("pls %d\n", counter);
//     local = local + 1;
//     counter = local;
//     pthread_mutex_unlock(&(arg->mutex));
//     return NULL;
// }
 
// #define NUM_OF_THREADS 100
 
// int main() {
//     pthread_t threads[NUM_OF_THREADS];
//     size_t i;
//     use_mutex_t param;
 
//     printf("counter = %d\n", counter);
//     pthread_mutex_init(&(param.mutex), NULL);
//     for (i = 0; i < NUM_OF_THREADS/2; i++)
// 	{
//         pthread_create(&threads[i], NULL, minus, &param);
//     }
//     for (; i < NUM_OF_THREADS; i++) {
//         pthread_create(&threads[i], NULL, plus, &param);
//     }
//     for (i = 0; i < NUM_OF_THREADS; i++) {
//         pthread_join(threads[i], NULL);
//     }
//     pthread_mutex_destroy(&(param.mutex));
//     printf("counter = %d", counter);
//     return 0;
// }