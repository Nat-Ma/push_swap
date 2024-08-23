/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:01:18 by nrauh             #+#    #+#             */
/*   Updated: 2024/08/23 17:03:39 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	print_bin(char octet)
{
	int	i;

	i = 8;
	ft_printf("n: %d\n", octet);
	while (i--)
	{
		ft_printf("%d", octet >> i & 1);
	}
	ft_printf("\n");
}

void	set_pos(t_stack *head)
{
	t_stack	*curr;
	t_stack	*cmp;
	int		pos;

	curr = head;
	while (curr)
	{
		pos = 0;
		cmp = head;
		while (cmp)
		{
			if (cmp->nbr < curr->nbr)
				pos++;
			cmp = cmp->next;
		}
		curr->pos = pos;
		curr = curr->next;
	}
	//print_stack(head);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int		size;
	int		p;
	int		i;
	int		bits;

	i = 0;
	size = stack_size(*a);
	if (size == 8)
		bits = 3;
	else if (size == 16)
		bits = 4;
	else if (size == 256)
		bits = 8;
	else if (size == 512)
		bits = 9;
	else
		bits = 10;
	set_pos(*a);
	while (i < bits)
	{
		//ft_printf("---------- byte position %d ----------\n", i);
		p = 0;
		while (p < size)
		{
			//print_bin((char)(*a)->nbr);
			//ft_printf("last nbr %d\n", (char)(*a)->nbr >> i & 1);
			if (((*a)->pos >> i & 1) == 0)
				pb(a, b);
			else
				ra(a);
			p++;
		}
		i++;
		while ((*b))
			pa(a, b);
		//ft_printf("print stack a after round of sorting");
		//print_stack(*a);
	}
	//ft_printf("END");
	//print_stack(*a);
}
