/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:59:30 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/16 13:37:56 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	ra(t_stack **head)
{
	t_stack	*first;
	t_stack	*curr;

	first = *head;
	curr = *head;
	while (curr->next)
		curr = curr->next;
	*head = first->next;
	first->next = NULL;
	curr->next = first;
	ft_printf("ra");
}

void	rb(t_stack **head)
{
	t_stack	*first;
	t_stack	*curr;

	first = *head;
	curr = *head;
	while (curr->next)
		curr = curr->next;
	*head = first->next;
	first->next = NULL;
	curr->next = first;
	ft_printf("rb");
}

void	rra(t_stack **head)
{
	t_stack	*last;
	t_stack	*curr;

	curr = *head;
	while (curr->next->next)
		curr = curr->next;
	last = curr->next;
	curr->next = NULL;
	last->next = *head;
	*head = last;
	ft_printf("rra");
}

void	rrb(t_stack **head)
{
	t_stack	*last;
	t_stack	*curr;

	curr = *head;
	while (curr->next->next)
		curr = curr->next;
	last = curr->next;
	curr->next = NULL;
	last->next = *head;
	*head = last;
	ft_printf("rrb");
}
