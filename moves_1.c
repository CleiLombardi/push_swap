/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:02:58 by roblomba          #+#    #+#             */
/*   Updated: 2026/04/02 19:49:14 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

int	ft_calculate_moves_to_top(int pos, int size)
{
	if (pos <= size / 2)
		return (pos);
	else
		return ((size - pos));
}

void	ft_set_moves(t_list *stack_a, int size_a, int size_b)
{
	int	moves_a;
	int	moves_b;

	moves_a = 0;
	moves_b = 0;
	while (stack_a != NULL)
	{
		moves_a = ft_calculate_moves_to_top(stack_a->pos, size_a);
		moves_b = ft_calculate_moves_to_top(stack_a->target_pos, size_b);
		if (moves_a <= size_a / 2 && moves_b <= size_b / 2)
			stack_a->moves = ft_whosbigger(moves_a, moves_b);
		else if (moves_a > size_a / 2 && moves_b > size_b / 2)
			stack_a->moves = ft_whosbigger(moves_a, moves_b);
		else
			stack_a->moves = moves_a + moves_b;
		stack_a = stack_a->next;
	}
}

t_list	*ft_find_cheapest_move(t_list *stack_a)
{
	int		cheapest_moves;
	t_list	*cheapest_node;

	cheapest_node = NULL;
	cheapest_moves = INT_MAX;
	while (stack_a != NULL)
	{
		if (stack_a->moves < cheapest_moves)
		{
			cheapest_moves = stack_a->moves;
			cheapest_node = stack_a;
		}
		stack_a = stack_a->next;
	}
	return (cheapest_node);
}

static void	ft_rotate_both(t_list **stack_a, t_list **stack_b, t_list *ch_node)
{
	int	size_a;
	int	size_b;
	int	moves_a;
	int	moves_b;

	size_a = ft_count_nodes(*stack_a);
	size_b = ft_count_nodes(*stack_b);
	if (ch_node->pos <= size_a / 2 && ch_node->target_pos <= size_b / 2)
	{
		moves_a = ch_node->pos;
		moves_b = ch_node->target_pos;
		while (moves_a-- > 0 && moves_b-- > 0)
			rr(stack_a, stack_b);
	}
	else if (moves_a > size_a / 2 && moves_b > size_b / 2)
	{
		moves_a = size_a - ch_node->pos;
		moves_b = size_b - ch_node->target_pos;
		while (moves_a > 0 && moves_b > 0)
		{
			rrr(stack_a, stack_b);
			moves_a--;
			moves_b--;
		}
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
	ft_rotate_both(stack_a, stack_b, ch_node, size_a, size_b);
	while (ch_node->pos > 0)
	{
		ra(stack_a);
		ch_node->pos--;
	}
	while (ch_node->target_pos > 0)
	{
		rb(stack_b);
		ch_node->target_pos--;
	}
	pb(stack_a, stack_b);
}
