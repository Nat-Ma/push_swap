/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 09:00:44 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/16 08:28:42 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	unique_nums(char *nums)
{
	int	ascii[256] = {0};

	while (*nums)
	{
		if (ascii[(int)*nums])
		{
			ft_print_error("No duplicates are allowed");
			return (1);
		}
		ascii[(int)*nums] = 1;
		nums++;
	}
	return (0);
}

int	in_int_range(char *nums)
{
	long	n;

	while (*nums)
	{
		n = ft_atol((const char *)nums);
		if (n < INT_MIN || n > INT_MAX)
		{
			ft_print_error("Number not in int range...");
			return (0);
		}
		nums++;
	}
	return (1);
}

int	only_digits(char *nums)
{
	if (*nums == '-' || *nums == '+')
		nums++;
	while(*nums)
	{
		if (ft_isdigit(*nums))
			nums++;
		else
		{
			ft_print_error("All Inputs must be digits.");
			return (0);
		}
	}
	return (1);
}

int	validate_input(char *nums)
{
	if (only_digits(nums)
		&& unique_nums(nums)
		&& in_int_range(nums))
		return (1);
	return (0);
}
