/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:22:13 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/29 15:40:20 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	free_all(t_stack **a, t_stack **b)
{
	free_stack(*a);
	free_stack(*b);
}

void	sort_all(t_stack **a, t_stack **b)
{
	unsigned int	size;

	size = stack_size(*a);
	if (already_sorted(a))
		;
	else if (size == 1)
		ft_print_error();
	else if (size <= 3)
		sort_three(a);
	else if (size == 4)
		sort_four(a, b);
	else if (size <= 5)
		sort_five(a, b);
	else if (size)
		radix_sort(a, b);
}

int	main(int argc, char **argv)
{
	char	**nums;
	t_stack	*a;
	t_stack	*b;

	a = NULL;
	b = NULL;
	nums = NULL;
	if (argc == 1)
		return (1);
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		if (!nums)
		{
			ft_print_error();
			return (1);
		}
		a = init_stack(a, nums);
		free_nums(nums);
	}
	if (argc > 2)
		a = init_stack(a, argv + 1);
	if (!a)
		return (1);
	sort_all(&a, &b);
	free_all(&a, &b);
	return (0);
}
