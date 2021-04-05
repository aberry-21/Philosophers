/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validation_value.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:35:13 by aberry            #+#    #+#             */
/*   Updated: 2021/04/05 21:17:03 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int			ft_validation_value(int argc, char const *argv[],\
															t_data *input_data)
{
	int		counter;
	int		*prt_struct;
	long	value;

	counter = 0;
	prt_struct = (int *)input_data;
	while (counter < argc - 1)
	{
		value = ft_get_number(argv[counter + 1]);
		if (ft_ismoreint(value, argv[counter + 1]))
		{
			printf(BAD_ARG);
			return (1);
		}
		prt_struct[counter] = (int)value;
		++counter;
	}
	if (input_data->number_of_philo > 500)
	{
		printf(MANY_PHILO);
		return (1);
	}
	return (0);
}
