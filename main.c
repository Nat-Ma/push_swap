/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:22:13 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/16 10:29:48 by natalierauh      ###   ########.fr       */
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
		ft_printf("node: %d\n", curr->nbr);
		curr = curr->next;
	}
}

int	main(int argc, char **argv)
{
	char	**nums;
	t_stack	*a;

	a = NULL;
	nums = NULL;
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		if (!nums)
			return (1);
		a = init_stack(a, nums);
		ft_printf("Free nums cause theyre now in stack\n");
		free_nums(nums);
	}
	if (argc > 2)
		a = init_stack(a, argv + 1);
	print_stack(a);
	sa(&a);
	print_stack(a);
	free_stack(a);
	nums = NULL;
	a = NULL;
	return (0);
}
