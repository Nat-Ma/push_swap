/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   my_sort.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/17 13:13:02 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/29 11:39:55 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	closer_to_top(t_stack *head, int n)
{
	int		top;
	t_stack	*curr;

	top = 0;
	curr = head;
	while(curr->nbr != n)
	{
		top++;
		curr = curr->next;
	}
	return (top <= (int)stack_size(head) / 2);
}

void	rotate_b_to_max(t_stack **b, int max)
{
	while ((*b)->nbr != max)
	{
		if (closer_to_top(*b, max))
			rb(b);
		else
			rrb(b);
	}
}

void	rotate_b_to_range(t_stack **b, int n, int *bottom)
{
	while (n < (*b)->nbr || n > *bottom)
	{
		*bottom = (*b)->nbr;
		rb(b);
	}
}

void	rotate_a_to_range(t_stack **a, int n, int *bottom)
{
	while (n > (*a)->nbr || n < *bottom)
	{
		*bottom = (*a)->nbr;
		ra(a);
	}
}

void	rotate_a_to_min(t_stack **a, int min)
{
	while ((*a)->nbr != min)
	{
		if (closer_to_top(*a, min))
			ra(a);
		else
			rra(a);
	}
}

void	sort(t_stack **a, t_stack **b)
{
	int		size;
	int		bottom;
	int		min;
	int		max;

	size = stack_size(*a);
	while (size > 3)
	{
		if (!(*b))
		{
			bottom = (*a)->nbr;
			min = (*a)->nbr;
			max = (*a)->nbr;
			pb(a, b);
		}
		else if ((*a)->nbr > max)
		{
			rotate_b_to_max(b, max);
			max = (*a)->nbr;
			bottom = min;
			pb(a, b);
		}
		else if ((*a)->nbr < min)
		{
			rotate_b_to_max(b, max);
			bottom = min;
			min = (*a)->nbr;
			pb(a, b);
		}
		else
		{
			rotate_b_to_range(b, (*a)->nbr, &bottom);
			pb(a, b);
		}
		size--;
	}
	sort_three(a);
	rotate_b_to_max(b, max);
	size = stack_size(*b);
	min = (*a)->nbr;
	max = find_max(*a);
	bottom = max;
	while (size)
	{
		if ((*b) && (*b)->nbr > max)
		{
			rotate_a_to_min(a, min);
			bottom = min;
			max = (*b)->nbr;
			pa(a, b);
		}
		else if ((*b) && (*b)->nbr < min)
		{
			rotate_a_to_min(a, min);
			min = (*b)->nbr;
			pa(a, b);
		}
		else if ((*b))
		{
			rotate_a_to_range(a, (*b)->nbr, &bottom);
			pa(a, b);
		}
		size--;
	}
	rotate_a_to_min(a, min);
	// ft_printf("---------- FINISSSHHH ----------");
	// print_stack((*a));
}
