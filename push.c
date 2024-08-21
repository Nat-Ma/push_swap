/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 13:46:18 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/19 19:17:32 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	push_to_front(t_stack **head, t_stack *node)
{
	if (head && node)
	{
		if (*head)
		{
			//ft_printf("set next node to next head...\n");
			node->next = *head;
		}
		else
		{
			//ft_printf("set next node to NULL...\n");
			node->next = NULL;
		}
		*head = node;
	}
}

void	pa(t_stack **head_a, t_stack **head_b)
{
	t_stack	*second;

	//ft_printf("push from b to a\n");
	if (*head_b)
	{
		second = (*head_b)->next;
		push_to_front(head_a, *head_b);
		*head_b = second;
		ft_printf("pa\n");
	}
}

void	pb(t_stack **head_a, t_stack **head_b)
{
	t_stack	*second;

	//ft_printf("push from a to b");
	if (*head_a)
	{
		second = (*head_a)->next;
		push_to_front(head_b, *head_a);
		*head_a = second;
		ft_printf("pb\n");
	}
}
