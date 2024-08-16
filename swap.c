/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 08:44:21 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/16 16:27:03 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

// void	swap_values(t_stack *a, t_stack *b)
// {
// 	int	tmp;

// 	tmp = a->nbr;
// 	a->nbr = b->nbr;
// 	b->nbr = tmp;
// }

void    swap_nodes(t_stack **head, t_stack *first, t_stack *second)
{
    t_stack    *tmp;

    tmp = first;
    first->next = second->next;
    second->next = tmp;
    first = second;
    *head = first;
}

void	sa(t_stack **head)
{
	t_stack *curr;
	size_t	len;

	curr = *head;
	len = 0;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	if (len >= 2)
	{
		swap_nodes(head, *head, (*head)->next);
		ft_printf("sa\n");
	}
}

void	sb(t_stack **head)
{
	t_stack *curr;
	size_t	len;

	curr = *head;
	len = 0;
	while (curr)
	{
		len++;
		curr = curr->next;
	}
	if (len >= 2)
	{
		swap_nodes(head, *head, (*head)->next);
		ft_printf("sb\n");
	}
}

void	ss(t_stack **head_a, t_stack **head_b)
{
	sa(head_a);
	sb(head_b);
}
