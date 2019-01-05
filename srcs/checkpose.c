/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   checkpose.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibatyrb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/25 14:46:18 by aibatyrb          #+#    #+#             */
/*   Updated: 2019/01/05 10:38:53 by dilaouid         ###   ########.fr       */
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

t_coord	ft_occurence(char **tetri, char c, t_coord q)
{
	q.occ0 = 0;
	while (tetri[q.occ0])
	{
		q.occ1 = 0;
		while (tetri[q.occ0][q.occ1])
		{
			if (tetri[q.occ0][q.occ1] == c)
				return (q);
			q.occ1++;
		}
		q.occ0++;
	}
	return (q);
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
	int i;
	int j;

	q.lg = ft_strlen(q.matrice[0]);
	i = 0;
	q = ft_occurence(tetri, '#', q);
	while (tetri[i] && (j = 0) == 0)
	{
		while (tetri[i][j])
		{
			if (((j - q.occ1 + q.y) < 0 || (j - q.occ1 + q.y) >= q.lg ||
	(i - q.occ0 + q.x) < 0 || (i - q.occ0 + q.x) >= q.lg) && tetri[i][j] == '#')
				return (0);
			else if (tetri[i][j] == '#' &&
					q.matrice[i - q.occ0 + q.x][j - q.occ1 + q.y] != '.')
				return (0);
			else if (tetri[i][j] == '#' &&
					q.matrice[i - q.occ0 + q.x][j - q.occ1 + q.y] == '.')
				q.matrice[i - q.occ0 + q.x][j - q.occ1 + q.y] = 'A' + nb;
			j++;
		}
		i++;
	}
	return (1);
}
