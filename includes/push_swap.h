/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: natalierauh <natalierauh@student.42.fr>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:23:21 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/16 14:30:06 by natalierauh      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_C
# define PUSH_SWAP_C

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"

typedef struct s_stack {
	int				nbr;
	size_t			len;
	struct s_stack	*next;
}					t_stack;

t_stack	*init_stack(t_stack *node, char **nums);
void	free_nums(char **nums);
void	free_stack(t_stack *stack);
int		valid_input(char **nums, int size);
void	ft_print_error(char *err_msg);
long	ft_atol(const char *num);
void	sa(t_stack **head);
void	sb(t_stack **head);
void	ra(t_stack **head);
void	rb(t_stack **head);
void	rra(t_stack **head);
void	rrb(t_stack **head);
void	pa(t_stack **head_a, t_stack **head_b);
void	pb(t_stack **head_a, t_stack **head_b);

#endif
