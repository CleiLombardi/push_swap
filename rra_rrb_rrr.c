/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rra_rrb_rrr.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:02:58 by roblomba          #+#    #+#             */
/*   Updated: 2026/03/22 19:25:02 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

static void	reverse_rotate(t_list **stack)
{
	t_list	*current;
	t_list	*prev;

	prev = NULL;
	current = *stack;
	while (current->next != NULL)
	{
		prev = current;
		current = current->next;
	}
	current->next = *stack;
	*stack = current;
	prev->next = NULL;
}

void	rra(t_list **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	reverse_rotate(stack_a);
	write (1, "rra\n", 4);
}

void	rrb(t_list **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	reverse_rotate(stack_b);
	write (1, "rrb\n", 4);
}

void	rrr(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	reverse_rotate(stack_a);
	reverse_rotate(stack_b);
	write (1, "rrr\n", 4);
}
