/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 13:35:57 by dilaouid          #+#    #+#             */
/*   Updated: 2018/11/21 13:44:58 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <string.h>

void	*ft_memmove(void *dst, const void *src, size_t len)
{
	int		i;
	char	*mdest;
	char	*msrc;

	if (len != 0)
	{
		if (dst < src)
			ft_memcpy(dst, src, len);
		else
		{
			mdest = (char*)dst;
			msrc = (char*)src;
			i = len;
			while (i-- != 0)
				mdest[i] = msrc[i];
		}
	}
	return (dst);
}
