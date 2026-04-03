/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap_header.h                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 20:09:02 by roblomba          #+#    #+#             */
/*   Updated: 2026/03/30 21:42:18 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_HEADER_H
# define PUSH_SWAP_HEADER_H

# include <stdlib.h>
# include <unistd.h>
# include <limits.h>

typedef struct s_list
{
	int				value;
	int				index;	
	int				pos;
	int				target_pos;
	int				moves;
	struct s_list	*next;
}	t_list;
//find_min_max_pos.c
int		ft_find_min_pos(t_list *stack);
int		ft_find_max_pos(t_list *stack);
int		ft_whosbigger(int a, int b);
//free_stack.c
void	free_stack(t_list **stack);
//moves.c
int		ft_calculate_moves_to_top(int pos, int size);
void	ft_set_moves(t_list *stack_a, int size_a, int size_b);
t_list	*ft_find_cheapest_move(t_list *stack_a);
void	ft_do_cheapest_move(t_list **stack_a, t_list **stack_b);
//pa_pb.c
void	pa(t_list **stack_a, t_list **stack_b);
void	pb(t_list **stack_a, t_list **stack_b);
//parsing_and_error.c
int		input_is_valid(char *str);
long	ft_atoi_long(char *str);
int		ft_has_duplicates(int argc, char **argv);
void	ft_error(void);
//position_and_target.c
void	ft_set_positions(t_list *stack);
int		ft_find_target_pos(t_list *stack_b, int value_a);
void	ft_set_target(t_list *stack_a, t_list *stack_b);
//ra_rb_rr.c
void	ra(t_list **stack_a);
void	rb(t_list **stack_b);
void	rr(t_list **stack_a, t_list **stack_b);
//rra_rrb_rrr.c
void	rra(t_list **stack_a);
void	rrb(t_list **stack_b);
void	rrr(t_list **stack_a, t_list **stack_b);
//sa_sb_ss.c
void	sa(t_list **stack_a);
void	sb(t_list **stack_b);
void	ss(t_list **stack_a, t_list **stack_b);
//sort_small.c
void	ft_sort_three(t_list **stack);
void	ft_sort_five(t_list **stack_a, t_list **stack_b);
//stack_utils.c
t_list	*ft_new_node(int value);
void	ft_node_to_bottom(t_list **lst, t_list *new_node);
int		ft_count_nodes(t_list *stack);

#endif
