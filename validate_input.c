/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 09:00:44 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/16 10:23:32 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	unique_nums(char **nums, int size)
{
	int		ascii[256] = {0};
	int		index;

	while (size--)
	{
		index = *nums[size];
		if (ascii[index])
		{
			ft_print_error("No duplicates are allowed");
			return (0);
		}
		ascii[index] = 1;
	}
	return (1);
}

int	in_int_range(char **nums, int size)
{
	long	n;

	while (size--)
	{
		n = ft_atol((const char *)nums[size]);
		if (n < INT_MIN || n > INT_MAX)
		{
			ft_print_error("Number not in int range...");
			return (0);
		}
	}
	return (1);
}

int	only_digits(char **nums, int size)
{
	if (**nums == '-' || **nums == '+')
		nums++;
	while(size--)
	{
		if (!ft_isdigit(*nums[size]))
		{
			ft_print_error("All Inputs must be digits.");
			return (0);
		}
	}
	return (1);
}

int	valid_input(char **nums, int size)
{
	if (only_digits(nums, size)
		&& unique_nums(nums, size)
		&& in_int_range(nums, size))
		return (1);
	return (0);
}
