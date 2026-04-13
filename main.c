	/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:02:58 by roblomba          #+#    #+#             */
/*   Updated: 2026/04/11 19:31:14 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	ft_has_duplicates_is_valid(argc, argv);
	if (ft_create_stack(&stack_a, argc, argv) == 1)
		return (1);
	if (ft_count_nodes(stack_a) > 1 && !ft_is_sorted(stack_a))
	{
		if (ft_count_nodes(stack_a) == 2)
			sa(&stack_a);
		else if (ft_count_nodes(stack_a) == 3)
			ft_sort_three(&stack_a);
		else if (ft_count_nodes(stack_a) <= 5)
			ft_sort_five(&stack_a, &stack_b);
		else
			sort_turk(&stack_a, &stack_b);
	}
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
