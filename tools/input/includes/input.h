/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   input.h                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 18:05:01 by aberry            #+#    #+#             */
/*   Updated: 2021/04/09 18:24:41 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef INPUT_H
# define INPUT_H

# include <unistd.h>
# include <stdio.h>
# include "utils.h"

# define BAD_ARG "Input: arguments must be int number\n"
# define MANY_ARG "Input: too many arguments\n"
# define FEW_ARG "Input: too few arguments\n"
# define MANY_PHILO "Input: too many thread\n"

typedef struct s_data
{
	int				number_of_philo;
	int				time_to_die;
	int				time_to_eat;
	int				time_to_sleep;
	int				number_of_lunch;
}					t_data;

/*
********************************************************************************
*/

/*
** Проверяет, что количество аргументов 4 или 5 
*/
int				ft_check_argument_size(int argc);

/*
** Проверяет, что аргументы являются положительными числами
*/
int				ft_check_argument_value(int argc, char const *argv[]);

/*
** Проверяет, что числа в пределах инт (а также количество потоков меньше 500) и
** заполняет поля структуры t_data
*/
int				ft_validation_value(int argc, char const *argv[], \
															t_data *input_data);

/*
** Инизиализирует структуру t_data
*/
t_data			*ft_init_simulation_arg(int argc, char const *argv[]);

/*
********************************************************************************
*/

#endif