/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:45:55 by dilaouid          #+#    #+#             */
/*   Updated: 2018/11/21 13:43:44 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*mdest;
	unsigned char	*msrc;
	unsigned int	i;

	i = 0;
	if (n != 0)
	{
		mdest = (unsigned char *)dest;
		msrc = (unsigned char *)src;
		while (n--)
		{
			mdest[i] = msrc[i];
			i++;
		}
	}
	return (dest);
}
