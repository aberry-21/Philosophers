/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   initialization_simulation.c                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:26:23 by aberry            #+#    #+#             */
/*   Updated: 2021/04/05 20:35:25 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>
#include "input.h"

t_data		*ft_init_simulation_arg(int argc, char const *argv[])
{
	t_data		*input_data;

	if (ft_check_argument_size(argc))
		return ((t_data *)0);
	if (ft_check_argument_value(argc, argv))
		return ((t_data *)0);
	input_data = (t_data *)malloc(sizeof(t_data));
	if (input_data == 0)
		return ((t_data *)0);
	memset((void *)input_data, 0, sizeof(t_data));
	if(ft_validation_value(argc, argv, input_data))
	{
		free(input_data);
		input_data = 0;
	}
	return (input_data);
}
