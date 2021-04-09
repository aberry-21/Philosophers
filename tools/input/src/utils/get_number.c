/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_number.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aberry <aberry@student.42.fr>              +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/04/02 16:05:00 by aberry            #+#    #+#             */
/*   Updated: 2021/04/09 18:37:21 by aberry           ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "input.h"

long	ft_get_number(const char *str)
{
	long	b;

	b = 0;
	while (ft_isspace(*str))
		str++;
	while (ft_isdigit(*str))
		b = b * 10 + *str++ - '0';
	return ((long)b);
}
