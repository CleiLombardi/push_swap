/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:02:58 by roblomba          #+#    #+#             */
/*   Updated: 2026/04/03 19:21:40 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h" 

static void	t_finish_rotate_a(t_list **stack_a, t_list *ch_node, int size_a)
{
	while (ch_node->pos > 0 && ch_node->pos <= size_a / 2)
	{
		ra(stack_a);
		ch_node->pos--;
	}
	while (ch_node->pos > 0 && ch_node->pos > size_a / 2)
	{
		rra(stack_a);
		ch_node->pos--;
	}
}

static void	ft_finish_rotate_b(t_list **stack_b, t_list *ch_node, int size_b)
{
	while (ch_node->target_pos > 0 && ch_node->target_pos <= size_b / 2)
	{
		rb(stack_b);
		ch_node->target_pos--;
	}
	while (ch_node->target_pos > 0 && ch_node->target_pos > size_b / 2)
	{
		rrb(stack_b);
		ch_node->target_pos--;
	}
}

void	ft_do_cheapest_move(t_list **stack_a, t_list **stack_b)
{
	t_list	*ch_node;
	int		size_a;
	int		size_b;

	size_a = ft_count_nodes(*stack_a);
	size_b = ft_count_nodes(*stack_b);
	ch_node = ft_find_cheapest_move(*stack_a);
	ft_rotate_both(stack_a, stack_b, ch_node);
	ft_finish_rotate_a(stack_a, ch_node, size_a);
	ft_finish_rotate_b(stack_b, ch_node, size_b);
	pb(stack_a, stack_b);
}
