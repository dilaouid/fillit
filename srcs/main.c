/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibatyrb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/28 19:56:21 by aibatyrb          #+#    #+#             */
/*   Updated: 2019/01/01 21:09:44 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

int													main(int argc, char **argv)
{
	char		***tetri;
	char		**matrice;
	char		**board;
	int			nb;

	if (argc != 2)
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
