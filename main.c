/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:22:13 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/16 14:55:06 by natalierauh      ###   ########.fr       */
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

int	main(int argc, char **argv)
{
	char	**nums;
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
	print_stack(a);
	/*sa(&a);
	print_stack(a);
	ra(&a);
	print_stack(a);
	rra(&a);
	print_stack(a);*/
	pb(&a, &b);
	ft_printf("STACK A");
	print_stack(a);
	ft_printf("STACK B");
	print_stack(b);
	pa(&a, &b);
	ft_printf("STACK A");
	print_stack(a);
	ft_printf("STACK B");
	print_stack(b);
	ft_printf("FREE STACKS");
	free_stack(a);
	free_stack(b);
	nums = NULL;
	a = NULL;
	return (0);
}
