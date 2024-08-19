/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:13:02 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/19 19:03:21 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort(t_stack **a, t_stack **b)
{
	int		size;
	int		bottom;
	int		min;
	int		max;

	size = stack_size(*a);
	while(size > 3)
	{
		if ((*a)->nbr > (*a)->next->nbr)
			sa(a);
		if (!(*b))
		{
			bottom = (*a)->nbr;
			min = (*a)->nbr;
			max = (*a)->nbr;
			pb(a, b);
		}
		else if ((*a)->nbr > max)
		{
			while ((*b)->nbr != max)
				rrb(b);
			max = (*a)->nbr;
			bottom = min;
			pb(a, b);
		}
		else if ((*a)->nbr < min)
		{
			while ((*b)->nbr != max)
				rrb(b);
			bottom = min;
			min = (*a)->nbr;
			pb(a, b);
		}
		else
		{
			while ((*a)->nbr < (*b)->nbr && (*a)->nbr > bottom)
			{
				bottom = (*b)->nbr;
				rb(b);
			}
			pb(a, b);
		}
		size--;
	}
}
