/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_mem.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 21:41:18 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/16 08:38:37 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

void	free_nums(char **nums)
{
	int	i;

	i = 0;
	ft_printf("Free nums cause theyre now in stack\n");
	while(nums[i])
	{
		ft_printf("free nums %d\n", ft_atoi(nums[i]));
		free(nums[i]);
		i++;
	}
	ft_printf("free nums pointer\n");
	free(nums);
}

void	free_stack(t_stack *stack)
{
	t_stack	*tmp;

	ft_printf("Free Stack!\n");
	while (stack)
	{
		ft_printf("free stack %d\n", stack->nbr);
		tmp = stack->next;
		ft_printf("free stack %p\n", stack);
		free(stack);
		ft_printf("free stack %p\n", stack);
		stack = tmp;
	}
	//free(tmp);
}
