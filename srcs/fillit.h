/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 14:06:16 by dilaouid          #+#    #+#             */
/*   Updated: 2019/01/02 13:48:11 by aibatyrb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "../libft/libft.h"
# include "../libft/get_next_line.h"
# include <fcntl.h>

typedef struct	s_coord
{
	char		**matrice;
	int			nb;
	int			x;
	int			y;
	int			occ0;
	int			occ1;
	int			i;
	int			j;
	int			lg;
	int			n;
	int			sqrt;
}				t_coord;

int				check_board(char **line);
int				check_validtetriminos(char **line);
int				check_tetrinumber(char **line);
char			**create_tetriminos(char *file, char **board);
int				check_emptyboard(char **line);
int				check_rows(char **line, int nbline);
int				ft_check_poses(char **tetri, t_coord q, int nb);
char			**ft_matrice(int nb);
t_coord			ft_occurence(char **tetri, char c, t_coord q);
char			***ft_tetri(int nb, int fd);
char			***ft_creation(int nb);
void			ft_clear(char **matrice, int nb);
char			**resolv(char ***tetri, int nb);
void			ft_print(char **matrice);
t_coord			ft_else(t_coord q, int nb);
t_coord			ft_nul(t_coord q, int n);
t_coord			ft_if(t_coord q, int nb);
char			***ft_tetri2(char **board, int nb);

#endif
