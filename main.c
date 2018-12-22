/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 14:35:32 by dilaouid          #+#    #+#             */
/*   Updated: 2018/12/22 16:30:05 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */


#include "fillit.h"
#include <stdio.h>

int		main(int argc, char **argv)
{
	char **board = NULL;
	int y;

	if (argc != 2)
		return (0);
	y = 0;
	board = create_tetriminos(argv[1], board);
	return (0);
}
