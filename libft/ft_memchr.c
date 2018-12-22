/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:45:14 by dilaouid          #+#    #+#             */
/*   Updated: 2018/11/24 10:58:23 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

void	*ft_memchr(const void *src, int c, size_t len)
{
	if (len == 0)
		return (NULL);
	while (len--)
	{
		if (*(unsigned char *)src != (unsigned char)c)
			src++;
		else
			return ((void *)src);
	}
	return (NULL);
}
