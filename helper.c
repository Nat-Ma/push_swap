/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   helper.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:45:42 by nrauh             #+#    #+#             */
/*   Updated: 2024/08/23 11:01:09 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	find_max(t_stack *head)
{
	t_stack	*curr;
	int		max;

	curr = head;
	max = 0;
	while (curr)
	{
		if (curr->nbr >= max)
			max = curr->nbr;
		curr = curr->next;
	}
	return (max);
}

int	find_min(t_stack *head)
{
	t_stack	*curr;
	int		min;

	curr = head;
	min = curr->nbr;
	while (curr)
	{
		if (curr->nbr < min)
			min = curr->nbr;
		curr = curr->next;
	}
	return (min);
}

void	print_stack(t_stack *head)
{
	t_stack	*curr;

	curr = head;
	ft_printf("\nPrinting stack\n");
	while (curr)
	{
		ft_printf("node: %d pos: %d next: %d\n", 
			curr->nbr, curr->pos, curr->next);
		curr = curr->next;
	}
}

size_t	stack_size(t_stack *head)
{
	size_t	size;
	t_stack	*curr;

	size = 0;
	curr = head;
	while (curr)
	{
		size++;
		curr = curr->next;
	}
	return (size);
}


