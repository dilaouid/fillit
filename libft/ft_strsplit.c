/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strsplit.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:52:02 by dilaouid          #+#    #+#             */
/*   Updated: 2018/11/26 11:32:21 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int		ft_size(char const *s, char c, int i)
{
	while (s[i] && s[i] != c)
		i++;
	return (i);
}

char			**ft_strsplit(char const *s, char c)
{
	char		**dest;
	int			i;
	int			x;
	int			y;

	if (s == NULL || (dest = (char **)malloc(sizeof(char *)
					* ft_countwords(s, c) + 1)) == NULL)
		return (NULL);
	i = 0;
	x = 0;
	while (s[i])
	{
		y = 0;
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		if (!(dest[x] = (char *)malloc(sizeof(char) * ft_size(s, c, i) + 1)))
			return (NULL);
		while (s[i] && s[i] != c)
			dest[x][y++] = s[i++];
		dest[x++][y] = '\0';
	}
	dest[x] = NULL;
	return (dest);
}
