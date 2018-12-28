/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 14:35:32 by dilaouid          #+#    #+#             */
/*   Updated: 2018/12/28 20:17:45 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void ft_print(char **matrice)
{
	int i;

	i = 0;
	while (matrice[i])
	{
		ft_putstr(matrice[i]);
		ft_putchar('\n');
		i++;
	}
}

t_coord ft_else(t_coord q, int nb)
{
	if (q.n == nb || q.n == 0)
	{
		q.matrice = ft_matrice(++q.sqrt);
		q = ft_nul(q);
	}
	else
	{
		q.occ = ft_occurence(q.matrice, 'A' + q.n);
		ft_clear(q.matrice, q.n);
		if (q.occ[1] < q.sqrt)
			q.y = q.occ[1] + 1;
		else if (q.occ[0] < q.sqrt)
		{
			q.y = 0;
			q.x = q.occ[0] + 1;
		}
		else
		{
			q.matrice = ft_matrice(++q.sqrt);
			q = ft_nul(q);
		}
	}
	return (q);
}

t_coord	ft_nul(t_coord q)
{
	q.n = 0;
	q.x = 0;
	q.y = 0;
	return (q);
}


char	**resolv(char ***tetri, int nb)
{
	t_coord q;

	q.sqrt = ft_sqrt(4 * nb);
	q.matrice = ft_matrice(q.sqrt);
	q = ft_nul(q);
	while (q.sqrt < 100)
	{
		if (ft_check_poses(tetri[q.n], q, q.n) == 0)
		{
			ft_clear(q.matrice, q.n + 1);
			if (q.y < q.sqrt)
				q.y++;
			else if (q.x < q.sqrt)
			{
				q.x++;
				q.y = 0;
			}
			else
				q = ft_else(q, nb);
		}
		else
		{
			q.n++;;
			if (q.n == nb)
				return (q.matrice);
		}
	}
	return (q.matrice);
}

int		main(int argc, char **argv)
{
	char ***tetri = NULL; 
	char **matrice;
	int i;
	int fd;
	char **board = NULL;
	int nbtetri;

	board = create_tetriminos(argv[1], board);
	nbtetri = check_tetrinumber(board);
	i = 0;
	if (argc != 2)
		return (0);
	fd = open(argv[1], O_RDONLY);
	if ((tetri = ft_tetri(nbtetri, fd)) == NULL)
		return (0);
	matrice = resolv(tetri, nbtetri);
	ft_print(matrice);
	exit(0);
}
