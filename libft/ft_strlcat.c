/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:11:49 by dilaouid          #+#    #+#             */
/*   Updated: 2018/11/21 13:49:30 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t i;
	size_t s1;
	size_t s2;

	s1 = 0;
	while (dst[s1] != '\0')
		s1++;
	i = 0;
	s2 = 0;
	while (src[i] != '\0' && s1 + i < size - 1)
	{
		if (size != 0)
			dst[s1 + i] = src[i];
		i++;
		s2++;
	}
	if (size != 0)
		dst[s1 + i] = '\0';
	while (src[s2] != '\0')
		s2++;
	if (size < s1)
		return (s2 + size);
	return (s1 + s2);
}
