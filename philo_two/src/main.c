/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:55:29 by aberry            #+#    #+#             */
/*   Updated: 2021/04/13 14:33:31 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "simulation.h"

int	main(int argc, char const *argv[])
{
	int			status;

	status = ft_init_simulation(&g_simulation, argc, argv);
	if (status != SUCCESS)
	{
		ft_destroy_simulation(&g_simulation);
		return (FAIL);
	}
	if (g_simulation.input_data->number_of_lunch == -1 || \
					g_simulation.input_data->number_of_lunch != 0)
		ft_create_supervisord();
	ft_destroy_simulation(&g_simulation);
	return (SUCCESS);
}
