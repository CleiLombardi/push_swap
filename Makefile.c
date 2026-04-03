/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   Makefile.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/04/03 19:57:03 by roblomba          #+#    #+#             */
/*   Updated: 2026/04/03 20:10:17 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

NAME = push_swap
CC = cc
CFLAGS = -Wall -Wextra -Werror

SRC = 


// NAME = push_swap
// CC	= cc
// CFLAGS	= -Wall -Wextra -Werror 
// LIBFT_PATH	= ./libft
// LIBFT		= $(LIBFT_PATH)/libft.a
// INC			= -I . -I ./libft

// SRC = main.c handle_errors.c stack_init.c stack_utils.c push.c swap.c rotate.c reverse_rotate.c sort_three.c turk_algorithm.c targets.c optimize.c costs.c
// OBJ = $(SRC:.c=.o)

// all: $(LIBFT) $(NAME)

// $(LIBFT):
// 	@make -C $(LIBFT_PATH)

// $(NAME): $(OBJ)
// 	$(CC) $(CFLAGS) $(OBJ) $(LIBFT) -o $(NAME)
// 	@echo "✅ Push_swap compilato!"

// %.o: %.c
// 	$(CC) $(CFLAGS) $(INC) -c $< -o $@

// clean:
// 	rm -f $(OBJ)
// 	@make -C $(LIBFT_PATH) clean

// fclean: clean
// 	rm -f $(NAME)
// 	@make -C $(LIBFT_PATH) fclean

// re: fclean all

// .PHONY: all clean fclean re

