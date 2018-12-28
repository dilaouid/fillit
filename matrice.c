/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   matrice.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibatyrb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 16:34:21 by aibatyrb          #+#    #+#             */
/*   Updated: 2018/12/28 18:09:50 by aibatyrb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	***ft_tetri(int nb, int fd)
{
	char	*line;
	char	***tetri;
	int		i;
	int		j;

	tetri = ft_creation(nb);
	j = 0;
	while (get_next_line(fd, &line) > 0)
	{
		if (line[0] != '\n' && (i = 0) == 0)
		{
			while (i < 4)
			{
				ft_strcpy(tetri[j][i], line);
				i++;
				free(line);
				get_next_line(fd, &line);
			}
			j++;
		}
		else
			free(line);
	}
	close(fd);
	return (tetri);
}

char	***ft_creation(int nb)
{
	int		i;
	int		j;
	char	***tetri;

	if ((tetri = (char***)malloc(sizeof(char **) * (nb + 1))) == NULL)
		return (NULL);
	i = 0;
	tetri[nb] = 0;
	while (i < nb)
	{
		j = 0;
		if ((tetri[i] = (char**)malloc(sizeof(char *) * 5)) == NULL)
			return (NULL);
		while (j < 4)
		{
			if ((tetri[i][j] = (char*)malloc(sizeof(char) * 5)) == NULL)
				return (NULL);
			j++;
		}
		tetri[i][j] = 0;
		i++;
	}
	return (tetri);
}
