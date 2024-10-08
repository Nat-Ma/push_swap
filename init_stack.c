/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:03:43 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/28 19:45:18 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stack	*new_node(t_stack *head, int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
	{
		ft_print_error();
		free_stack(head);
		return (NULL);
	}
	//ft_printf("alloced new node %p with data %d\n", new, data);
	new->nbr = data;
	new->pos = -1;
	new->next = NULL;
	//ft_printf("created head with num %d head %p\n", new->nbr, head);
	return (new);
}

t_stack	*init_stack(t_stack *head, char **nums)
{
	t_stack	*new;
	size_t	size;

	size = 0;
	head = NULL;
	if (!nums)
		return (NULL);
	while (nums[size])
		size++;
	if (!valid_input(nums, size))
		return (0);
	//ft_printf("---------- INPUT VALID ----------\n");
	while (size--)
	{
		//ft_printf("Size: %d, Num %s\n", size, nums[size]);
		new = new_node(head, ft_atoi(nums[size]));
		if (!new)
		{
			free_stack(head);
			return (0);
		}
		new->next = head;
		head = new;
	}
	return (head);
}
