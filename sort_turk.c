/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:02:58 by roblomba          #+#    #+#             */
/*   Updated: 2026/04/13 17:33:26 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

void	ft_push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	int	target_a;
	int	size_a;
	int	next_pos;

	if (!*stack_b)
		return ;
	ft_set_positions(*stack_a);
	ft_set_positions(*stack_b);
	target_a = ft_find_target_pos (*stack_a, (*stack_b)->value);
	size_a = ft_count_nodes (*stack_a);
	next_pos = target_a + 1;
	if (next_pos >= size_a)
		next_pos = 0;
	ft_rotate_a_to_pos(stack_a, next_pos);
	pa(stack_a, stack_b);
}

void	sort_turk(t_list **stack_a, t_list **stack_b)
{
	int	count_nodes_a;

	count_nodes_a = ft_count_nodes(*stack_a);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	count_nodes_a = count_nodes_a - 2;
	while (count_nodes_a > 3)
	{
		ft_set_positions(*stack_a);
		ft_set_positions(*stack_b);
		ft_set_target(*stack_a, *stack_b);
		ft_set_moves(*stack_a, count_nodes_a, ft_count_nodes(*stack_b));
		ft_do_cheapest_move(stack_a, stack_b);
		count_nodes_a--;
	}
	ft_sort_three(stack_a);
	while (*stack_b != NULL)
	{
		ft_push_back_to_a(stack_a, stack_b);
	}
	ft_rotate_min_to_top(stack_a);
}
