/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:22:13 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/16 08:36:42 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	main(int argc, char **argv)
{
	char	**nums;
	t_stack	*a;
	t_stack *curr;

	a = NULL;
	nums = NULL;
	if (argc == 2)
	{
		nums = ft_split(argv[1], ' ');
		if (!nums)
			return (0);
		a = init_stack(a, nums);
		free_nums(nums);
	}
	if (argc > 2)
		a = init_stack(a, argv + 1);
	curr = a;
	while (curr)
	{
		ft_printf("node: %d\n", curr->nbr);
		curr = curr->next;
	}
	sa(&a);
	curr = a;
	while (curr)
	{
		ft_printf("node: %d\n", curr->nbr);
		curr = curr->next;
	}
	free_stack(a);
	nums = NULL;
	a = NULL;
	return (0);
}
