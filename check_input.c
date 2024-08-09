/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_input.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/09 09:00:44 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/09 09:38:45 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "includes/push_swap.h"

int	invalid_input(char *num)
{
	if (*num == '-')
		num++;
	while(*num)
	{
		if (ft_isdigit(*num))
			num++;
		else
		{
			ft_print_error("Error\nAll Inputs must be digits.\n");
			return (1);
		}
	}
	return (0);
}
