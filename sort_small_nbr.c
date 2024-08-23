/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small_nbr.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:15:29 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/23 14:09:42 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	already_sorted(t_stack **head_a)
{
	t_stack	*curr;

	curr = *head_a;
	if (!curr || !curr->next)
		return (1);
	while (curr->next != NULL)
	{
		if (curr->nbr > curr->next->nbr)
			return (0);
		curr = curr->next;
	}
	return (1);
}

void	sort_three(t_stack **head_a)
{
	int	max;

	max = find_max(*head_a);
	if (max == (*head_a)->nbr)
		ra(head_a);
	else if (max == (*head_a)->next->nbr)
		rra(head_a);
	if ((*head_a)->nbr > (*head_a)->next->nbr)
		sa(head_a);
}

void	sort_four(t_stack **a, t_stack **b)
{
	int		min;

	min = find_min(*a);
	while ((*a)->nbr != min)
		ra(a);
	pb(a, b);
	sort_three(a);
	pa(a, b);
}

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;
	int	max;
	int	size;

	max = find_max(*a);
	min = find_min(*a);
	size = 5;
	while (size--)
	{
		if ((*a)->nbr == min || (*a)->nbr == max)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	while ((*b))
	{
		pa(a, b);
		if ((*a)->nbr == max)
			ra(a);
	}
}
