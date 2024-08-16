/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:59:30 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/16 18:36:26 by natalierauh      ###   ########.fr       */
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
	// need to add a condition when called from rr
	ft_printf("ra\n");
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
	// need to add a condition when called from rr
	ft_printf("rb\n");
}

void	rr(t_stack **head_a, t_stack **head_b)
{
	ra(head_a);
	rb(head_b);
	ft_printf("rr\n");
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
	// need to add a condition when called from rrr
	ft_printf("rra\n");
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
	// need to add a condition when called from rrr
	ft_printf("rrb\n");
}

void	rrr(t_stack **head_a, t_stack **head_b)
{
	rra(head_a);
	rrb(head_b);
	ft_printf("rrr\n");
}
