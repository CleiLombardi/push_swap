/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:57:03 by roblomba          #+#    #+#             */
/*   Updated: 2026/04/03 20:39:43 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRCS	= find_min_find_max_pos.c \
		  free_stack.c \
		  moves_1.c \
		  moves_2.c \
		  pa_pb.c \
		  parsing_and_error.c \
		  position_and_target.c \
		  ra_rb_rr.c \
		  rra_rrb_rrr.c \
		  sa_sb_ss.c \
		  sort_small.c \
		  sort_turk.c \
		  stack_utils.c \
		  main.c
		  
OBJS	= $(SRCS:.c=.o)

all:		$(NAME)

$(NAME):	$(OBJS)
		$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
		@echo "WOWO abbiamo compilato Push_swap!!!"

%.o: %.c
$(CC) $(CFLAGS) $(INC) -c $< -o $@

clean:
		rm -f $(OBJS)

fclean:		clean
		rm -f $(NAME)

re:		fclean all

.PHONY:		all clean fclean re