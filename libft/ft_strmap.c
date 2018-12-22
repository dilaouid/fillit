/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:50:26 by dilaouid          #+#    #+#             */
/*   Updated: 2018/11/21 13:50:01 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

char	*ft_strmap(char const *s, char (*f)(char))
{
	int				i;
	char			*dst;

	i = 0;
	if (s == NULL || f == NULL)
		return (NULL);
	dst = (char *)malloc(sizeof(char) * ft_strlen(s) + 1);
	if (dst == NULL)
		return (NULL);
	dst = ft_strcpy(dst, s);
	while (dst[i])
	{
		dst[i] = (*f)(dst[i]);
		i++;
	}
	return (dst);
}
