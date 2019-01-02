/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibatyrb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:56:21 by aibatyrb          #+#    #+#             */
/*   Updated: 2019/01/02 15:36:08 by dilaouid         ###   ########.fr       */
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
//	int			j;

	if (argc != 2)
	{
		ft_putendl("usage: fillit source_file");
		return (0);
	}
	board = NULL;
	board = create_tetriminos(argv[1], board);
	nb = check_tetrinumber(board);
	tetri = ft_tetri(nb, open(argv[1], O_RDONLY));
	while (1)
	{}
	matrice = resolv(tetri, nb);
	ft_print(matrice);
	i = 0;
/*	while (matrice[i])
	{
		ft_putendl("matrice not null");
		free(matrice[i]);
		i++;
	}
	while (1)
	{}
	i = 0;
	while (tetri[i])
	{
		j = 0;
		while (tetri[i][j])
		{
			ft_putendl("tetri not null");
			free(tetri[i][j++]);
		}
		free(tetri[i]);
		i++;
	i = 0;
	}
	while (board[i])
	{
		ft_putendl("board not null");
		free(board[i++]);
	}
	ft_putendl("here"); */
	while (1)
	{}
	return (0);
}
