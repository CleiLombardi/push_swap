/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   position_and_target.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:02:58 by roblomba          #+#    #+#             */
/*   Updated: 2026/04/10 19:03:35 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

void	ft_set_positions(t_list *stack)
{
	int	pos;

	pos = 0;
	while (stack != NULL)
	{
		stack->pos = pos;
		stack = stack->next;
		pos++;
	}
}

int	ft_find_target_pos(t_list *stack_b, int value_a)
{
	int		target_pos;
	int		best_target;
	t_list	*stack_b_copy;

	stack_b_copy = stack_b;
	target_pos = 0;
	best_target = INT_MIN;
	while (stack_b != NULL)
	{
		if (stack_b->value < value_a && stack_b->value > best_target)
		{
			best_target = stack_b->value;
			target_pos = stack_b->pos;
		}
		stack_b = stack_b->next;
	}
	if (best_target == INT_MIN)
		target_pos = ft_find_max_pos (stack_b_copy);
	return (target_pos);
}

void	ft_set_target(t_list *stack_a, t_list *stack_b)
{
	int	current_value;
	int	target_pos;

	while (stack_a != NULL)
	{
		current_value = stack_a->value;
		target_pos = ft_find_target_pos(stack_b, current_value);
		stack_a->target_pos = target_pos;
		stack_a = stack_a->next;
	}
}
