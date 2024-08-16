/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   swap.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 08:44:21 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/09 15:36:28 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	swap_values(t_stack *a, t_stack *b)
{
	int	tmp;

	tmp = a->nbr;
	a->nbr = b->nbr;
	b->nbr = tmp;
}

void    swap_nodes(t_stack **head, t_stack *a, t_stack *b)
{
    t_stack    *tmp;

    tmp = a;
    a->next = b->next;
    b->next = tmp;
    a = b;
    *head = a;
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
