/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   radix_sort.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 10:01:18 by nrauh             #+#    #+#             */
/*   Updated: 2024/08/29 00:30:58 by natalierauh      ###   ########.fr       */
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

int	calc_bits(int n)
{
	int	res;

	res = 0;
	if (n == 0 || n == 1)
		return (2);
	while (n > 0)
	{
		n = n / 2;
		res++;
	}
	return (res);
}

// void	radix_sort(t_stack **a, t_stack **b)
// {
// 	int		size;
// 	int		pos;
// 	int		i;
// 	int		bits;
// 	int		count;

// 	i = 0;
// 	size = stack_size(*a);
// 	bits = calc_bits(size);
// 	set_pos(*a);
// 	while (i < bits)
// 	{
// 		pos = 0;
// 		size = stack_size(*a);
// 		count = 0;
// 		while (pos < size)
// 		{
// 			//print_bin((char)(*a)->pos);
// 			//ft_printf("pos %d last nbr %d\n", (*a)->pos, (char)(*a)->pos >> i & 1);
// 			if (((*a)->pos >> i & 1) == 0)
// 			{
// 				count++;
// 				pb(a, b);
// 			}
// 			else
// 				ra(a);
// 			pos++;
// 		}
// 		ft_printf("elements added to b %d\n", count);
// 		print_stack(*a);
// 		print_stack(*b);
// 		ft_printf("i: %d\n", i);
// 		pos = 0;
// 		while (pos < count)
// 		{
// 			if (i + 1 > calc_bits((*b)->pos))
// 				rb(b);
// 			else if (*b)
// 				pa(a, b);
// 			pos++;
// 		}
// 		i++;
// 		ft_printf("Pushed back....");
// 		print_stack(*a);
// 		print_stack(*b);
// 	}
// 	while ((*b))
// 		pa(a, b);
// 	//print_stack(*a);
// }

void	radix_sort(t_stack **a, t_stack **b)
{
	int		size;
	int		pos;
	int		i;
	int		bits;

	i = 0;
	size = stack_size(*a);
	bits = calc_bits(size);
	set_pos(*a);
	while (i < bits)
	{
		pos = 0;
		while (pos < size)
		{
			if (((*a)->pos >> i & 1) == 0)
				pb(a, b);
			else
				ra(a);
			pos++;
		}
		i++;
		while ((*b))
			pa(a, b);
	}
}
