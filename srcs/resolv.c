/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   resolv.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibatyrb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 20:39:53 by aibatyrb          #+#    #+#             */
/*   Updated: 2019/01/05 10:34:40 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"
#include <stdio.h>

void	ft_print(char **matrice)
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

t_coord	ft_else(t_coord q, int nb)
{
	if (q.n == 0 && nb != -1)
		q = ft_nul(q, 0);
	else if (--q.n != -1)
	{
		q = ft_occurence(q.matrice, 'A' + q.n, q);
		ft_clear(q.matrice, q.n);
		if (q.occ1 < q.sqrt)
		{
			q.x = q.occ0;
			q.y = q.occ1 + 1;
		}
		else if (q.occ0 < q.sqrt)
		{
			q.y = 0;
			q.x = q.occ0 + 1;
		}
		else
			q = ft_nul(q, 0);
	}
	return (q);
}

t_coord	ft_nul(t_coord q, int n)
{
	if (n == 0)
	{
		if (q.matrice)
			free(q.matrice);
		if ((q.matrice = ft_matrice(++q.sqrt)) == NULL)
			exit(0);
	}
	q.n = 0;
	q.x = 0;
	q.y = 0;
	return (q);
}

char	**resolv(char ***tetri, int nb)
{
	t_coord q;

	q.sqrt = ft_sqrt(4 * nb);
	if ((q.matrice = ft_matrice(q.sqrt)) == NULL)
		exit(0);
	q = ft_nul(q, 1);
	while (q.sqrt < 100)
	{
		if (ft_check_poses(tetri[q.n], q, q.n) == 0)
		{
			q = ft_if(q, nb);
		}
		else
		{
			q.n++;
			q.x = 0;
			q.y = 0;
			if (q.n == nb)
				return (q.matrice);
		}
	}
	return (q.matrice);
}

t_coord	ft_if(t_coord q, int nb)
{
	ft_clear(q.matrice, q.n);
	if (q.y < q.sqrt)
		q.y++;
	else if (q.x < q.sqrt)
	{
		q.x++;
		q.y = 0;
	}
	else
		q = ft_else(q, nb);
	return (q);
}
