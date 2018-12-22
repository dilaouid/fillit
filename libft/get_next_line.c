/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/12/14 15:58:26 by dilaouid          #+#    #+#             */
/*   Updated: 2018/12/22 13:35:06 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "get_next_line.h"
#include "libft.h"

static char			*fill(const int fd, char *buffer, int *check)
{
	char			lineread[BUFF_SIZE + 1];
	char			*del;

	*check = read(fd, lineread, BUFF_SIZE);
	if (lineread[*check - 1] != '\n' && *check < BUFF_SIZE && *check > 0)
	{
		lineread[*check] = '\n';
		lineread[*check + 1] = '\0';
	}
	else
		lineread[*check] = '\0';
	del = buffer;
	buffer = ft_strjoin(buffer, lineread);
	ft_strdel(&del);
	return (buffer);
}

int					get_next_line(const int fd, char **line)
{
	static char		*buffer = NULL;
	int				check;
	char			*chr;

	if (fd < 0 || !line)
		return (-1);
	if (!buffer)
		buffer = ft_strnew(0);
	check = 1;
	while (check > 0)
	{
		if ((chr = ft_strchr(buffer, '\n')) != NULL)
		{
			*chr++ = '\0';
			*line = ft_strdup(buffer);
			if (!line)
				return (-1);
		
			ft_memmove(buffer, chr, ft_strlen(chr) + 1);
			return (1);
		}
		buffer = fill(fd, buffer, &check);
	}
	if (check == 0)
		*line = ft_strdup(buffer);
	return (check);
}
