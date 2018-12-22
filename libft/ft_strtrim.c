/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:52:29 by dilaouid          #+#    #+#             */
/*   Updated: 2018/11/26 11:31:59 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static int			ft_destlen(const char *s)
{
	int				i;
	int				len;

	i = 0;
	len = 0;
	while (s[i])
		i++;
	i--;
	while (s[i] == ' ' || s[i] == '\t' || s[i] == '\n')
	{
		len++;
		i--;
	}
	return (len);
}

char				*ft_strtrim(char const *s)
{
	int				i;
	int				start;
	char			*dest;

	if (s == NULL)
		return (NULL);
	start = 0;
	i = 0;
	while (s[start] == ' ' || s[start] == '\t' || s[start] == '\n')
		start++;
	if (ft_destlen(s) != (int)ft_strlen(s))
	{
		if (!(dest = (char *)malloc(sizeof(char)
			* (ft_strlen(s) - (ft_destlen(s) + start) + 1))))
			return (NULL);
		while (ft_destlen(s) == 0 && s[start])
			dest[i++] = s[start++];
		while (s[start + ft_destlen(s)] != '\0')
			dest[i++] = s[start++];
		dest[i] = '\0';
		return (dest);
	}
	return (ft_strdup("\0"));
}
