/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:57:39 by dilaouid          #+#    #+#             */
/*   Updated: 2018/12/22 17:45:45 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_board(char **line)
{
	int x;
	int y;

	x = 0;
	y = 0;
	while (line[y])
	{
		if ((ft_countchar(line[y], '.') + ft_countchar(line[y], '#') != 4)
				|| ft_strlen(line[y]) != 5)
		{
			if (line[y][0] != '\n')
				return (0);
		}
		y++;
		printf("next line\n");
	}
	printf("checkboard OK\n");
	return (1);
}

int	check_validtetriminos(char **line)
{
	int x;
	int y;
	int shapesize;

	y = 0;
	while (line[y])
	{
		x = 0;
		shapesize = 0;
		while (line[y][x])
		{
			if (line[y][x] == '#' && (line[y][x - 1] != '#' && line[y][x + 1] != '#'
						&& line[y - 1][x] != '#' && line[y + 1][x] != '#'))
				return (0);
			else if (line[y][x] == '#')
				shapesize++;
			x++;
		}
		if (shapesize != 4)
			return (0);
		y++;
	}
	return (1);
}

int	check_tetrinumber(char **line)
{
	int y;
	int nb;

	nb = 1;
	y = 0;
	while (line[y])
	{
		if (ft_strlen(line[y]) == 1)
			nb++;
		y++;
	}
	return (nb);
}
