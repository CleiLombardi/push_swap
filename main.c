/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:02:58 by roblomba          #+#    #+#             */
/*   Updated: 2026/04/04 16:01:50 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

int	main(int argc, char **argv)
{
	t_list	*stack_a;
	t_list	*stack_b;
	t_list	*new_node;
	int		i;

	stack_a = NULL;
	stack_b = NULL;
	if (argc < 2)
		return (0);
	ft_has_duplicates(argc, argv);
	i = 1;
	while (i < argc)
	{
		input_is_valid(argv[i]);
		new_node = ft_new_node (ft_atoi_long(argv[i]));
		if (!new_node)
			return (free_stack(&stack_a), 1);
		ft_node_to_bottom (&stack_a, new_node);
		i++;
	}
	if (ft_count_nodes(&stack_a) > 1)
		sort_turk(&stack_a, &stack_b);
	free_stack(&stack_a);
	free_stack(&stack_b);
	return (0);
}
