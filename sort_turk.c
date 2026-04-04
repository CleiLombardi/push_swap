/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_turk.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:02:58 by roblomba          #+#    #+#             */
/*   Updated: 2026/04/03 22:15:46 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

void	ft_push_back_to_a(t_list **stack_a, t_list **stack_b)
{
	int	max_pos;
	int	size_b;

	size_b = ft_count_nodes(*stack_b);
	max_pos = ft_find_max_pos(*stack_b);
	while (max_pos != 0)
	{
		if (max_pos > size_b / 2)
			rrb(stack_b);
		else
			rb(stack_b);
		max_pos = ft_find_max_pos(*stack_b);
	}
	pa(stack_a, stack_b);
}

void	sort_turk(t_list **stack_a, t_list **stack_b)
{
	int	count_na;

	count_na = ft_count_nodes(*stack_a);
	pb(stack_a, stack_b);
	pb(stack_a, stack_b);
	count_na = count_na - 2;
	while (count_na > 3)
	{
		ft_set_positions(*stack_a);
		ft_set_positions(*stack_b);
		ft_set_target(*stack_a, *stack_b);
		ft_set_moves(*stack_a, count_na, ft_count_nodes(*stack_b));
		ft_do_cheapest_move(stack_a, stack_b);
		count_na--;
	}
	ft_sort_three(stack_a);
	while (*stack_b != NULL)
	{
		ft_push_back_to_a(stack_a, stack_b);
	}
	ft_rotate_min_to_top(stack_a);
}
