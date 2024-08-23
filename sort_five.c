/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_five.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/22 14:53:51 by nrauh             #+#    #+#             */
/*   Updated: 2024/08/22 17:32:04 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	sort_five(t_stack **a, t_stack **b)
{
	int	min;
	int	max;
	int	size;

	max = find_max(*a);
	min = find_min(*a);
	size = 5;
	while (size--)
	{
		if ((*a)->nbr == min || (*a)->nbr == max)
			pb(a, b);
		else
			ra(a);
	}
	sort_three(a);
	while ((*b))
	{
		pa(a, b);
		if ((*a)->nbr == max)
			ra(a);
	}
	print_stack(*a);
}
