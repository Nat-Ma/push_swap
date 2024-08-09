/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:03:43 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/09 09:42:05 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stack	*init_stack(t_stack *head, char **nums)
{
	t_stack	*new;
	int		size;

	size = 0;
	head = NULL;
	while (nums[size])
		size++;
	//head->len = size;
	while (size)
	{
		new = malloc(sizeof(t_stack));
		if (!new || invalid_input(nums[--size]))
		{
			free_stack(head);
			return (0);
		}
		new->nbr = ft_atoi(nums[size]);
		ft_printf("created head with num %d\n", new->nbr);
		new->next = head;
		head = new;
	}
	return (head);
}
