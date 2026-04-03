/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   free_stack.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:35:26 by roblomba          #+#    #+#             */
/*   Updated: 2026/03/29 17:33:09 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h" 

void	free_stack(t_list **stack)
{
	t_list	*tmp;
	t_list	*current;

	if (!stack || !*stack)
		return ;
	current = *stack;
	while (current != NULL)
	{
		tmp = current->next;
		free(current);
		current = tmp;
	}
	*stack = NULL;
}
