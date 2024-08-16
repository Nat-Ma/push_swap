/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 12:19:58 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/09 12:31:54 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

static int    ft_isspace(const char c)
{
    if ((c >= 9 && c <= 13) || c == ' ')
        return (1);
    return (0);
}

long	ft_atol(const char *num)
{
	long	res;
	int			sign;

	res = 0;
	sign = 1;
	while (ft_isspace(*num))
		num++;
	if (*num == '+')
		num++;
	if (*num == '-')
	{
		sign = -1;
		num++;
	}
	while (*num && ft_isdigit(*num))
	{
		res = res * 10 + *num - '0';
		num++;
	}
	return (sign * res);
}
