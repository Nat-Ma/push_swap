/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   validate_input.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 09:00:44 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/16 13:24:31 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	unique_nums(char **nums, int size)
{
	int	i;
	int	j;
	int	n1;
	int	n2;

	i = 0;
	while (i < size)
	{
		j = 0;
		n1 = ft_atoi((const char *)nums[i]);
		while (j < size)
		{
			n2 = ft_atoi((const char *)nums[j]);
			if (i != j && n1 == n2)
			{
				ft_print_error("No duplicates are allowed");
				return (0);
			}
			j++;
		}
		i++;
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
	int	i;

	while(size--)
	{
		i = 0;
		if (nums[size][i] == '-' || nums[size][i] == '+')
			i++;
		while (nums[size][i])
		{
			if (!ft_isdigit(nums[size][i]))
			{
				ft_print_error("All Inputs must be digits.");
				return (0);
			}
			i++;
		}
	}
	return (1);
}

int	valid_input(char **nums, int size)
{
	if (only_digits(nums, size)
		&& in_int_range(nums, size)
		&& unique_nums(nums, size))
		return (1);
	return (0);
}
