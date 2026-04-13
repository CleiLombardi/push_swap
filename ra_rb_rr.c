/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ra_rb_rr.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:09:02 by roblomba          #+#    #+#             */
/*   Updated: 2026/03/22 19:10:00 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

static void	rotate(t_list **stack)
{
	t_list	*first;
	t_list	*last;

	first = *stack;
	*stack = first->next;
	first->next = NULL;
	last = *stack;
	while (last->next != NULL)
		last = last->next;
	last->next = first;
}

void	ra(t_list **stack_a)
{
	if (!stack_a || !*stack_a || !(*stack_a)-> next)
		return ;
	rotate(stack_a);
	write(1, "ra\n", 3);
}

void	rb(t_list **stack_b)
{
	if (!stack_b || !*stack_b || !(*stack_b)-> next)
		return ;
	rotate(stack_b);
	write(1, "rb\n", 3);
}

void	rr(t_list **stack_a, t_list **stack_b)
{
	if (!stack_a || ! *stack_a || !(*stack_a)->next)
		return ;
	if (!stack_b || ! *stack_b || !(*stack_b)->next)
		return ;
	rotate(stack_a);
	rotate(stack_b);
	write (1, "rr\n", 3);
}
