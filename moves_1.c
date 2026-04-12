/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_1.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:02:58 by roblomba          #+#    #+#             */
/*   Updated: 2026/04/12 15:46:10 by roblomba         ###   ########.fr       */
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
		if ((stack_a->pos <= size_a / 2) == (stack_a->target_pos <= size_b / 2))
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

static void	ft_do_rotation(t_list **a, t_list **b, int shared, int rotation)
{
	while (shared > 0)
	{
		if (rotation == 1)
			rrr(a, b);
		else
			rr(a, b);
		shared--;
	}
}

void	ft_rotate_both(t_list **stack_a, t_list **stack_b, t_list *ch_node)
{
	int	size_a;
	int	size_b;
	int	shared;

	size_a = ft_count_nodes(*stack_a);
	size_b = ft_count_nodes(*stack_b);
	if (ch_node->pos <= size_a / 2 && ch_node->target_pos <= size_b / 2)
	{
		shared = ft_whossmaller(ch_node->pos, ch_node->target_pos);
		ch_node->pos = ch_node->pos - shared;
		ch_node->target_pos = ch_node->target_pos - shared;
		ft_do_rotation(stack_a, stack_b, shared, 0);
	}
	else if (ch_node->pos > size_a / 2 && ch_node->target_pos > size_b / 2)
	{
		ch_node->pos = size_a - ch_node->pos;
		ch_node->target_pos = size_b - ch_node->target_pos;
		shared = ft_whossmaller(ch_node->pos, ch_node->target_pos);
		ch_node->pos = ch_node->pos - shared;
		ch_node->target_pos = ch_node->target_pos - shared;
		ft_do_rotation(stack_a, stack_b, shared, 1);
	}
}
