/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibatyrb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:56:21 by aibatyrb          #+#    #+#             */
/*   Updated: 2019/01/02 15:15:37 by aibatyrb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int													main(int argc, char **argv)
{
	char		***tetri;
	char		**matrice;
	char		**board;
	int			nb;
	int			i;
	int			j;

	if (argc != 2)
	{
		ft_putendl("usage: fillit source_file");
		return (0);
	}
	board = NULL;
	board = create_tetriminos(argv[1], board);
	nb = check_tetrinumber(board);
	tetri = ft_tetri(nb, open(argv[1], O_RDONLY));
	matrice = resolv(tetri, nb);
	ft_print(matrice);
	i = 0;
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			free(tetri[i][j]);
			j++;
		}
		free(tetri[i]);
		i++;
	}
	free(tetri);
	i = 0;
	while (matrice[i])
	{
		free(matrice[i]);
		i++;
	}
	free(matrice);
	i = 0;
	while (board[i])
	{
		free(board[i]);
		i++;
	}
	free(board);
	while (1)
	{}
	return (0);
}
