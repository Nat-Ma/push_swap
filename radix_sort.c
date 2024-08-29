/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:01:18 by nrauh             #+#    #+#             */
/*   Updated: 2024/08/29 11:34:35 by nrauh            ###   ########.fr       */
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
}

int	calc_bits(unsigned int n)
{
	int	result;

	result = 0;
	if (n == 0) 
		return (1);
	while (n > 0)
	{
		n = n / 2;
		result++;
	}
	return (result);
}

void	radix_sort(t_stack **a, t_stack **b)
{
	int		size;
	int		p;
	int		i;
	int		bits;

	i = 0;
	size = stack_size(*a);
	bits = calc_bits(size);
	set_pos(*a);
	while (i < bits)
	{
		p = 0;
		while (p < size)
		{
			if (((*a)->pos >> i & 1) == 0)
				pb(a, b);
			else
				ra(a);
			p++;
		}
		i++;
		while ((*b))
			pa(a, b);
	}
}

