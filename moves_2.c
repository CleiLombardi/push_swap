/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:02:58 by roblomba          #+#    #+#             */
/*   Updated: 2026/04/02 19:57:41 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h" 

void	ft_rotate_min_to_top(t_list **stack_a)
{
	int	min_pos;
	int	size;
	int	moves;

	size = ft_count_nodes(*stack_a);
	min_pos = ft_find_min_pos(*stack_a);
	moves = ft_calculate_moves_to_top(min_pos, size);
	if (min_pos <= size / 2)
	{
		while (moves > 0)
		{
			ra(stack_a);
			moves--;
		}
	}
	else
	{
		while (moves > 0)
		{
			rra(stack_a);
			moves--;
		}
	}
}
