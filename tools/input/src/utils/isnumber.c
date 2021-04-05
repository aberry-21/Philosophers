/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   isnumber.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/03/27 17:14:18 by aberry            #+#    #+#             */
/*   Updated: 2021/04/05 19:41:22 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include <stdbool.h>
#include "input.h"

int			ft_isnumber(const char *line)
{
	size_t		counter;

	counter = 0;
	while (line[counter])
	{
		if (ft_isdigit(line[counter]) == 0)
			return (false);
		++counter;
	}
	return (true);
}
