/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parsing_and_error.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: roblomba <roblomba@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/03/16 21:02:58 by roblomba          #+#    #+#             */
/*   Updated: 2026/04/03 22:25:54 by roblomba         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap_header.h" 

int	input_is_valid(char *str)
{
	int	i;

	i = 0;
	if (str[i] == '+' || str[i] == '-' )
		i++;
	if (str[i] == '\0')
		ft_error ();
	while (str[i] >= '0' && str[i] <= '9')
		i++;
	if (str[i] == '\0')
		return (1);
	ft_error ();
	return (0);
}

long	ft_atoi_long(char *str)
{
	long	result;
	int		sign;
	int		i;

	result = 0;
	sign = 1;
	i = 0;
	if (!str)
		return (0);
	if (str[i] == '+' || str[i] == '-')
	{
		if (str[i] == '-')
			sign = -1;
		i++;
	}
	while (str[i] >= '0' && str[i] <= '9')
	{
		result = result * 10 + (str[i] - '0');
		if (result > INT_MAX || (result * sign) < INT_MIN)
			ft_error ();
		i++;
	}
	return (result * sign);
}

int	ft_has_duplicates(int argc, char **argv)
{
	int	i;
	int	j;

	i = 1;
	while (i < argc)
	{
		j = i + 1;
		while (j < argc)
		{
			if (ft_atoi_long (argv[i]) == ft_atoi_long(argv[j]))
				ft_error ();
			j++;
		}
		i++;
	}
	return (0);
}

void	ft_error(void)
{
	write (2, "Error\n", 6);
	exit (1);
}
