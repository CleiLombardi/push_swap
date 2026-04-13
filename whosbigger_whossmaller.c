/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   whosbigger_whossmaller.c                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:02:58 by roblomba          #+#    #+#             */
/*   Updated: 2026/04/09 20:38:24 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h"

int	ft_whosbigger(int a, int b)
{
	if (a > b)
		return (a);
	return (b);
}

int	ft_whossmaller(int a, int b)
{
	if (a < b)
		return (a);
	return (b);
}
