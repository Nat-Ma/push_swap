/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rotate.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 11:59:30 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/16 12:43:45 by natalierauh      ###   ########.fr       */
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
