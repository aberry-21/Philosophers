/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   argument_size.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 20:32:45 by aberry            #+#    #+#             */
/*   Updated: 2021/04/09 18:26:59 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

int	ft_check_argument_size(int argc)
{
	if (argc > 6)
	{
		printf(MANY_ARG);
		return (1);
	}
	if (argc < 5)
	{
		printf(FEW_ARG);
		return (1);
	}
	return (0);
}
