/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   find_min_find_max_pos.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:02:58 by roblomba          #+#    #+#             */
/*   Updated: 2026/04/02 18:51:02 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

int	ft_find_min_pos(t_list *stack)
{
	int		min_value;
	int		pos;
	int		min_pos;

	min_value = stack->value;
	pos = 0;
	min_pos = 0;
	while (stack != NULL)
	{
		if (stack->value < min_value)
		{
			min_value = stack->value;
			min_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (min_pos);
}

int	ft_find_max_pos(t_list *stack)
{
	int		max_value;
	int		pos;
	int		max_pos;

	max_value = stack->value;
	pos = 0;
	max_pos = 0;
	while (stack != NULL)
	{
		if (stack->value > max_value)
		{
			max_value = stack->value;
			max_pos = pos;
		}
		pos++;
		stack = stack->next;
	}
	return (max_pos);
}

int	ft_whosbigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}
