/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:57:39 by dilaouid          #+#    #+#             */
/*   Updated: 2018/12/23 15:48:06 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

static int	valid_size(int shapesize)
{
	int i;

	i = 0;
	while (i < shapesize)
		i += 4;
	if (i == shapesize)
		return (1);
	return (0);
}

int	check_board(char **line)
{
	int x;
	int y;

	ft_putendl(RESET"\n-------CHECK IF THE BOARD IS VALID ...-------");
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
	}
	ft_putendl(GREEN"CHECK BOARD OK"RESET);
	return (1);
}

int	check_validtetriminos(char **line)
{
	int x;
	int y;
	int shapesize;

	ft_putendl("\n-------CHECK IF THE TETRIMINOS ARE VALID ...-------");
	y = 0;
	shapesize = 0;
	while (line[y])
	{
		x = 0;
		while (line[y][x])
		{
			ft_putchar(line[y][x]);
			if (x == 0 && y == 0 && line[y][x] == '#'
					&& (line[y][x + 1] != '#' || line[y + 1][x] != '#'))
				return (0);
			else if (line[y][x] == '#' && (((x > 0 && line[y][x - 1] != '#')
						&& (line[y][x + 1] != '\n' && line[y][x + 1] != '#'))
						&& ((y > 0 && line[y - 1][x] != '#') && (line[y + 1]
						&& line[y + 1][x] != '#'))) && line[y][x + 1] != '\n')
				return (0);
			if (line[y][x] == '#')
				shapesize++;
			x++;
		}
		y++;
	}
	if (valid_size(shapesize) == 0)
		return (0);
	ft_putendl(GREEN"VALID TETRIMINOS"RESET);
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
