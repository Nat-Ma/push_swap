/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   tiny_sort.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/16 18:15:29 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/20 00:55:31 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	find_max(t_stack **head)
{
	t_stack	*curr;
	int	pos;
	int	max;

	curr = *head;
	pos = 0;
	max = 0;
	while (curr)
	{
		if (curr->nbr >= max)
		{
			max = curr->nbr;
			pos++;
		}
		curr = curr->next;
	}
	return (pos);
}

void	tiny_sort(t_stack **head_a)
{
	int	pos;

	pos = find_max(head_a);
	//ft_printf("max %d\n", pos);
	if (pos == 1)
		ra(head_a);
	else if (pos == 2)
		rra(head_a);
	if ((*head_a)->nbr > (*head_a)->next->nbr)
		sa(head_a);
}
