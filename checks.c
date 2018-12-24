/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:57:39 by dilaouid          #+#    #+#             */
/*   Updated: 2018/12/24 19:01:10 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int	check_rows(char **line, int nbline)
{
	int rows;
	int y;

	y = 0;
	while (y < nbline)
	{
		rows = 0;
		while (ft_strlen(line[y]) == 5)
		{
			rows++;
			y++;
			if (y == nbline && rows == 4)
				return (1);
			else if (y == nbline && rows != 4)
				return (0);
		}
		if (rows != 4)
			return (0);
		y++;
	}
	return (1);
}

int	check_board(char **line)
{
	int x;
	int y;

	ft_putendl(RESET"\n-------CHECK IF THE BOARD IS VALID ...-------");
	x = 0;
	y = 0;
	if (check_emptyboard(line) == 0 || line[y][x] == '\n')
		return (0);
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

int	check_emptyboard(char **line)
{
	int y;
	int x;
	unsigned long dot;

	y = 0;
	dot = 0;
	while (line[y])
	{
		x = 0;
		while (line[y][x])
		{
			if (line[y][x] == '.')
				dot++;
			x++;
		}
		if (line[y][0] == '\n')
			dot = 0;
		if (dot == 16)
			return (0);
		y++;
	}
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
	if (shapesize % 4 != 0 || shapesize >= y)
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
