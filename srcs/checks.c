/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checks.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/21 17:57:39 by dilaouid          #+#    #+#             */
/*   Updated: 2018/12/30 14:44:07 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int					check_links(char **line, int x, int y, int *link)
{
	if (line[y][x] == '\n')
		return (*link);
	if (y > 0 && line[y - 1][0] != '\n' && line[y - 1][x] == '#')
		*link += 1;
	if (line[y + 1] && line[y + 1][0] != '\n' && line[y + 1][x] == '#')
		*link += 1;
	if (x > 0 && line[y][x - 1] == '#')
		*link += 1;
	if (line[y][x + 1] != '\n' && line[y][x + 1] == '#')
		*link += 1;
	return (*link);
}

int					check_rows(char **line, int nbline)
{
	int				rows;
	int				y;

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

int					check_board(char **line)
{
	int				x;
	int				y;

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
	return (1);
}

int					check_emptyboard(char **line)
{
	int				y;
	int				x;
	int				dot;

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

int					check_validtetriminos(char **line)
{
	int				x;
	int				y;
	int				shapesize;
	int				link;

	y = 0;
	shapesize = 0;
	link = 0;
	while (line[y])
	{
		x = 0;
		while (line[y][x])
		{
			if (line[y][x] == '#' && check_links(line, x, y, &link))
				shapesize++;
			x++;
		}
		y++;
		if ((line[y] && line[y][0] == '\n') && (link != 6 && link != 8))
			return (0);
		else if (line[y] && line[y][0] == '\n')
			link = 0;
	}
	return (!(shapesize % 4 != 0 || (link != 6 && link != 8)));
}
