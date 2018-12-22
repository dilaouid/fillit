/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:51:43 by dilaouid          #+#    #+#             */
/*   Updated: 2018/11/21 13:52:28 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strrchr(const char *s, int c)
{
	int		i;
	char	*dst;

	i = 0;
	dst = NULL;
	while (s[i])
	{
		if (s[i] == (char)c)
			dst = ((char *)s + i);
		i++;
	}
	if (s[i] == (char)c)
		dst = ((char *)s + i);
	return (dst);
}
