/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   read.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 13:35:57 by dilaouid          #+#    #+#             */
/*   Updated: 2018/12/23 23:16:45 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "fillit.h"

char	**create_tetriminos(char *file, char **board)
{
	char	*line;
	int		y;
	int		nbtetriminos;
	int		fd;
	int		nbline;
	y = 0;
	fd = open(file, O_RDONLY);
	board = (char **)malloc(sizeof(char *) * 104);
	if (board == NULL)
		return (NULL);
	while (get_next_line(fd, &line) > 0)
	{
		board[y] = ft_strdup(line);
		board[y][ft_strlen(line)] = '\n';
		y++;
		free(line);
	}
	close(fd);
	y = 0;
	while (board[y] != NULL)
		y++;
	nbline = y;
	printf("Number of lines: "GREEN"%d\n"RESET, y);
	while (y < 26)
		ft_memdel((void **)board[y++]);
	nbtetriminos = check_tetrinumber(board);
	printf("Nb of possible tetriminos: "GREEN"%d\n"RESET, nbtetriminos);
	if (check_board(board) == 0 || check_validtetriminos(board) == 0
			|| check_rows(board, nbline) == 0)
	{
		ft_putendl(RED"error"RESET);
		exit(0);
		return (NULL);
	}
	else
	{
		ft_putendl("\n-------CONCLUSION-------");
		ft_putendl(GREEN"OK!"RESET);
	}
	return (board);
}
