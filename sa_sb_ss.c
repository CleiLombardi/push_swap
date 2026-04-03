/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   sa_sb_ss.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:02:58 by roblomba          #+#    #+#             */
/*   Updated: 2026/03/22 18:41:09 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

void	sa(t_list **stack_a)
{
	t_list	*first;
	t_list	*second;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	first = *stack_a;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_a = second;
	write (1, "sa\n", 3);
}

void	sb(t_list **stack_b)
{
	t_list	*first;
	t_list	*second;

	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first = *stack_b;
	second = first->next;
	first->next = second->next;
	second->next = first;
	*stack_b = second;
	write (1, "sb\n", 3);
}

void	ss(t_list **stack_a, t_list **stack_b)
{
	t_list	*first_a;
	t_list	*second_a;
	t_list	*first_b;
	t_list	*second_b;

	if (!stack_a || !*stack_a || !(*stack_a)->next)
		return ;
	if (!stack_b || !*stack_b || !(*stack_b)->next)
		return ;
	first_a = *stack_a;
	second_a = first_a->next;
	first_a->next = second_a->next;
	second_a->next = first_a;
	*stack_a = second_a;
	first_b = *stack_b;
	second_b = first_b->next;
	first_b->next = second_b->next;
	second_b->next = first_b;
	*stack_b = second_b;
	write (1, "ss\n", 3);
}
