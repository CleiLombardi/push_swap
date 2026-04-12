/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   stack_create_and_free.c                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/17 15:35:26 by roblomba          #+#    #+#             */
/*   Updated: 2026/04/11 19:28:47 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h" 

int	ft_create_stack(t_list **stack_a, int argc, char **argv)
{
	t_list	*new_node;
	int		i;
	int		value;

	i = 1;
	while (i < argc)
	{
		input_is_valid(argv[i]);
		value = ft_atoi_long(argv[i]);
		new_node = ft_new_node(value);
		if (!new_node)
		{
			free_stack(stack_a);
			return (1);
		}
		ft_node_to_bottom(stack_a, new_node);
		i++;
	}
	return (0);
}

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
