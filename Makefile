# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    Makefile                                           :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: 2026/03/16 21:02:58 by roblomba          #+#    #+#              #
#    Updated: 2026/04/09 22:08:32 by roblomba         ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror
HEADER = push_swap_header.h

SRCS = find_min_find_max_pos.c main.c moves_1.c moves_2.c pa_pb.c \
 parsing_and_error.c position_and_target.c ra_rb_rr.c rra_rrb_rrr.c \
 sa_sb_ss.c sort_small.c sort_turk.c stack_create_and_free.c stack_nodes_utils.c \
 whosbigger_whossmaller.c

all: $(NAME)

OBJS = $(SRCS:.c=.o)

$(NAME): $(OBJS)
	$(CC) $(CFLAGS) $(OBJS) -o $(NAME)
	@echo "WOWO abbiamo compilato Push_swap!!!"
	
%.o: %.c $(HEADER)
	$(CC) $(CFLAGS) -c $< -o $@
	
clean:
	rm -f $(OBJS)
	
fclean: clean
	rm -f $(NAME)
	
re: fclean all

.PHONY: all clean fclean re
