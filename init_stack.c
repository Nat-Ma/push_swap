/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 20:03:43 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/16 08:24:44 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

t_stack	*new_node(t_stack *head, int data)
{
	t_stack	*new;

	new = malloc(sizeof(t_stack));
	if (!new)
	{
		free_stack(head);
		return (NULL);
	}
	ft_printf("alloced new %p\n", new);
	new->nbr = data;
	ft_printf("created head with num %d\n", new->nbr);
	new->next = head;
	head = new;
	return (new);
}

t_stack	*init_stack(t_stack *head, char **nums)
{
	t_stack	*new;
	size_t	size;

	size = 0;
	head = NULL;
	while (nums[size])
		size++;
	while (size)
	{
		if (!validate_input(nums[--size]))
		{
			free_stack(head);
			return (0);
		}
		new = new_node(head, ft_atoi(nums[size]));
		if (!new)
		{
			free_stack(head);
			return (0);
		}
		/*ft_printf("alloced new %p\n", new);
		new->nbr = ft_atoi(nums[size]);
		ft_printf("created head with num %d\n", new->nbr);*/
	}
	return (head);
}
