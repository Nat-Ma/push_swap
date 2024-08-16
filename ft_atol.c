/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atol.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 09:00:44 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/16 08:34:16 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	valid_input(char *num)
{
	long	n;

	n = ft_atol(num);
	if (n < INT_MIN || n > INT_MAX)
	{
		ft_print_error("Number is too big...");
		return (0);
	}
	if (*num == '-' || *num == '+')
		num++;
	while(*num)
	{
		if (ft_isdigit(*num))
			num++;
		else
		{
			ft_print_error("Error\nAll Inputs must be digits.\n");
			return (0);
		}
	}
	return (1);
}

