/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:51:18 by dilaouid          #+#    #+#             */
/*   Updated: 2018/11/25 12:38:49 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

char	*ft_strnew(size_t size)
{
	char	*dst;
	int		i;

	i = 0;
	dst = (char *)malloc(size + 1);
	if (dst == NULL)
		return (NULL);
	while (size--)
		dst[i++] = '\0';
	dst[i] = '\0';
	return (dst);
}
