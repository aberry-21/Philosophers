/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_value.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:34:39 by aberry            #+#    #+#             */
/*   Updated: 2021/04/05 20:34:42 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int			ft_check_argument_value(int argc, char const *argv[])
{
	int		counter;

	counter = 1;
	while (counter < argc)
	{
		if (ft_isnumber(argv[counter]) == 0)
		{
			printf(BAD_ARG);
			return (1);
		}
		++counter;
	}
	return (0);
}
