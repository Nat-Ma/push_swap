/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nrauh <nrauh@student.42berlin.de>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/08/08 19:23:21 by natalierauh       #+#    #+#             */
/*   Updated: 2024/08/23 14:53:17 by nrauh            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_C
# define PUSH_SWAP_C

#include "../libft/includes/libft.h"
#include "../libft/includes/ft_printf.h"

typedef struct s_stack {
	int				nbr;
	int				pos;
	struct s_stack	*next;
}					t_stack;

t_stack	*init_stack(t_stack *node, char **nums);
void	free_nums(char **nums);
void	free_stack(t_stack *stack);
int		valid_input(char **nums, int size);
void	ft_print_error(void);
long	ft_atol(const char *num);
void	sa(t_stack **head);
void	sb(t_stack **head);
void	ss(t_stack **head_a, t_stack **head_b);
void	ra(t_stack **head);
void	rb(t_stack **head);
void	rr(t_stack **head_a, t_stack **head_b);
void	rra(t_stack **head);
void	rrb(t_stack **head);
void	rrr(t_stack **head_a, t_stack **head_b);
void	pa(t_stack **head_a, t_stack **head_b);
void	pb(t_stack **head_a, t_stack **head_b);
void	sort_three(t_stack **head_a);
void	sort_four(t_stack **a, t_stack **b);
void	sort_five(t_stack **a, t_stack **b);
void	print_stack(t_stack *head);
size_t	stack_size(t_stack *head);
int		find_min(t_stack *head);
int		find_max(t_stack *head);
void	sort(t_stack **a, t_stack **b);
void	radix_sort(t_stack **a, t_stack **b);
int		already_sorted(t_stack **head_a);

#endif
