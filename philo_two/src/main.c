/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:55:29 by aberry            #+#    #+#             */
/*   Updated: 2021/04/11 18:42:59 by aberry           ###   ########.fr       */
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
	ft_create_supervisord();
	ft_destroy_simulation(&g_simulation);
	return (SUCCESS);
}
