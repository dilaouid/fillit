/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibatyrb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 14:46:18 by aibatyrb          #+#    #+#             */
/*   Updated: 2018/12/28 20:43:20 by aibatyrb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**ft_matrice(int nb)
{
	int		i;
	int		j;
	char	**matrice;

	i = 0;
	if ((matrice = (char **)malloc(sizeof(char*) * (nb + 1))) == NULL)
		return (NULL);
	matrice[nb] = 0;
	while (i < nb)
	{
		if ((matrice[i] = (char *)malloc(sizeof(char) * (nb + 1))) == NULL)
			return (NULL);
		i++;
	}
	i = 0;
	while (i < nb && (j = 0) == 0)
	{
		while (j < nb)
			matrice[i][j++] = '.';
		matrice[i][nb] = '\0';
		i++;
	}
	return (matrice);
}

int		*ft_occurence(char **tetri, char c)
{
	int *xy;

	if ((xy = (int *)malloc(sizeof(int) * 2)) == NULL)
		return (NULL);
	xy[0] = 0;
	while (tetri[xy[0]])
	{
		xy[1] = 0;
		while (tetri[xy[0]][xy[1]])
		{
			if (tetri[xy[0]][xy[1]] == c)
				return (xy);
			xy[1]++;
		}
		xy[0]++;
	}
	return (xy);
}

void	ft_clear(char **matrice, int nb)
{
	int i;
	int j;

	i = 0;
	while (matrice[i])
	{
		j = 0;
		while (matrice[i][j])
		{
			if (matrice[i][j] == 'A' + nb)
				matrice[i][j] = '.';
			j++;
		}
		i++;
	}
}

int		ft_check_poses(char **tetri, t_coord q, int nb)
{
	int *occ;
	int i;
	int j;

	q.lg = ft_strlen(q.matrice[0]);
	i = 0;
	occ = ft_occurence(tetri, '#');
	while (tetri[i] && (j = 0) == 0)
	{
		while (tetri[i][j])
		{
			if (((j - occ[1] + q.y) < 0 || (j - occ[1] + q.y) >= q.lg ||
	(i - occ[0] + q.x) < 0 || (i - occ[0] + q.x) >= q.lg) && tetri[i][j] == '#')
				return (0);
			else if (tetri[i][j] == '#' &&
					q.matrice[i - occ[0] + q.x][j - occ[1] + q.y] != '.')
				return (0);
			else if (tetri[i][j] == '#' &&
					q.matrice[i - occ[0] + q.x][j - occ[1] + q.y] == '.')
				q.matrice[i - occ[0] + q.x][j - occ[1] + q.y] = 'A' + nb;
			j++;
		}
		i++;
	}
	return (1);
}
