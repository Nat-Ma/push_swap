/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:13:02 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/20 01:21:46 by natalierauh      ###   ########.fr       */
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
			{
				rrb(b);
			}
			max = (*a)->nbr;
			bottom = min;
			pb(a, b);
		}
		else if ((*a)->nbr < min)
		{
			while ((*b)->nbr != max)
			{
				rb(b);
			}
			bottom = min;
			min = (*a)->nbr;
			pb(a, b);
		}
		else
		{
			while ((*a)->nbr < (*b)->nbr || (*a)->nbr > bottom)
			{
				bottom = (*b)->nbr;
				rb(b);
			}
			pb(a, b);
		}
		size--;
	}
	//tiny_sort(a);
	//ft_printf("---------- STACKS A and B ----------");
	//print_stack((*a));
	while ((*b)->nbr != max)
		rrb(b);
	//print_stack((*b));
	size = stack_size(*b);
	max = (*a)->nbr;
	while (size)
	{
		while ((*b)->nbr > (*a)->nbr)
			ra(a);
		pa(a, b);
		size--;
	}
	while ((*a)->nbr != max)
		rra(a);
	ra(a);
}
