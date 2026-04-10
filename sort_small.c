/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sort_small.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:02:58 by roblomba          #+#    #+#             */
/*   Updated: 2026/04/10 18:52:04 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

static void	ft_move_min_to_first(t_list **stack, int min_pos, int size)
{
	if (min_pos <= size / 2)
	{
		while (min_pos > 0)
		{
			ra (stack);
			min_pos --;
		}
	}
	else
	{
		min_pos = size - min_pos;
		while (min_pos > 0)
		{
			rra (stack);
			min_pos--;
		}
	}
}

void	ft_sort_three(t_list **stack)
{
	int	first;
	int	second;
	int	third;

	if (!stack || !*stack || !(*stack)->next || !(*stack)->next->next)
		return ;
	first = (*stack)->value;
	second = (*stack)->next->value;
	third = (*stack)->next->next->value;
	if (first > second && first > third)
	{
		ra(stack);
		if (second > third)
			sa(stack);
	}
	else if (second > first && second > third)
	{
		rra(stack);
		if (third > first)
			sa(stack);
	}
	else if (first > second)
		sa(stack);
}

void	ft_sort_five(t_list **stack_a, t_list **stack_b)
{
	int	size;

	if (!stack_a || !*stack_a)
		return ;
	size = ft_count_nodes (*stack_a);
	ft_move_min_to_first (stack_a, ft_find_min_pos(*stack_a), size);
	pb (stack_a, stack_b);
	size--;
	ft_move_min_to_first (stack_a, ft_find_min_pos(*stack_a), size);
	pb (stack_a, stack_b);
	ft_sort_three (stack_a);
	pa (stack_a, stack_b);
	pa (stack_a, stack_b);
}
