/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ismoreint.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/05 19:10:52 by aberry            #+#    #+#             */
/*   Updated: 2021/04/09 18:37:28 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <limits.h>
#include "input.h"

int	ft_ismoreint(long number, const char *line)
{
	return ((number > (long)INT_MAX) || (number < (long)INT_MIN) \
												|| ft_strlen(line) > 11);
}
