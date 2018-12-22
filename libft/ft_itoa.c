/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:44:24 by dilaouid          #+#    #+#             */
/*   Updated: 2018/11/26 11:35:26 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"
#include <stdlib.h>

static char		*ft_fillstr(char *nb, int n)
{
	int			i;

	i = 0;
	if (n == -2147483648)
	{
		nb[i++] = '-';
		nb[i++] = '8';
		nb[i++] = '4';
		n = 21474836;
	}
	if (n < 0)
	{
		nb[i++] = '-';
		n = -n;
	}
	while (n > 0)
	{
		nb[i++] = (n % 10) + 48;
		n /= 10;
	}
	nb[i] = '\0';
	return (nb);
}

char			*ft_itoa(int n)
{
	char		*nb;

	if (n == 0)
	{
		nb = ft_strdup("0");
		return (nb);
	}
	nb = (char *)malloc(sizeof(char) * (ft_nbchiffres(n) + 1));
	if (nb == NULL)
		return (NULL);
	ft_fillstr(nb, n);
	ft_strrev(nb);
	return (nb);
}
