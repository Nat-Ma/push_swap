/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:22:13 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/20 00:59:07 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	print_stack(t_stack *head)
{
	t_stack *curr;

	curr = head;
	ft_printf("\nPrinting stack\n");
	while (curr)
	{
		ft_printf("node: %d next: %d\n", curr->nbr, curr->next);
		curr = curr->next;
	}
}

size_t	stack_size(t_stack *head)
{
	size_t	size;
	t_stack	*curr;

	size = 0;
	curr = head;
	while (curr)
	{
		size++;
		curr = curr->next;
	}
	return (size);
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
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		if (!nums)
			return (1);
		a = init_stack(a, nums);
		free_nums(nums);
		if (!a)
			exit (0);
	}
	if (argc > 2)
		a = init_stack(a, argv + 1);
	size = stack_size(a);
	if (size <= 3)
		tiny_sort(&a);
	else
		sort(&a, &b);
	//ft_printf("---- SORTED ----");
	//print_stack(a);
	free_stack(a);
	free_stack(b);
	nums = NULL;
	a = NULL;
	b = NULL;
	return (0);
}
