/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   fillit.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/22 14:06:16 by dilaouid          #+#    #+#             */
/*   Updated: 2018/12/22 16:47:19 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FILLIT_H
# define FILLIT_H

# include "libft/libft.h"
# include "libft/get_next_line.h"
# include <fcntl.h>
# include <stdio.h>

int	check_board(char **line);
int	check_validtetriminos(char **line);
int	check_tetrinumber(char **line);
char	**create_tetriminos(char *file, char **board);

#endif
