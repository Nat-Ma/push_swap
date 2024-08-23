/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:22:13 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/23 16:26:47 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	free_all(t_stack *a, t_stack *b)
{
	free_stack(a);
	free_stack(b);
}

int	main(int argc, char **argv)
{
	char	**nums;
	size_t	size;
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
		a = init_stack(a, nums);
		if (!a)
			exit (0);
		free_nums(nums);
	}
	if (argc > 2)
		a = init_stack(a, argv + 1);
	size = stack_size(a);
	if (size == 0)
		;
	else if (already_sorted(&a))
		;
	else if (size == 1)
		ft_print_error();
	else if (size <= 3)
		sort_three(&a);
	else if (size == 4)
		sort_four(&a, &b);
	else if (size <= 5)
		sort_five(&a, &b);
	else if (size)
		radix_sort(&a, &b);
	//ft_printf("---- SORTED ----");
	//print_stack(a);
	free_all(a, b);
	return (0);
}
