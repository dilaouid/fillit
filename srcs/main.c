/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibatyrb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:56:21 by aibatyrb          #+#    #+#             */
/*   Updated: 2018/12/30 20:02:59 by aibatyrb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int													main(int argc, char **argv)
{
	char		***tetri;
	char		**matrice;
	char		**board;
	int			nb;

	if (argc == 1)
	{
		ft_putendl("usage: fillit source_file");
		return (0);
	}
	board = NULL;
	nb = 16;
	board = create_tetriminos(argv[1], board);
	nb = check_tetrinumber(board);
	tetri = ft_tetri(nb, open(argv[1], O_RDONLY));
	matrice = resolv(tetri, nb);
	ft_print(matrice);
	free(matrice);
	free(tetri);
	free(board);
	return (0);
}
