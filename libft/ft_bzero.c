/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:43:18 by dilaouid          #+#    #+#             */
/*   Updated: 2018/11/21 14:02:30 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

void	ft_bzero(void *s1, size_t n)
{
	if (n != 0)
	{
		while (n--)
			((unsigned char *)s1)[n] = '\0';
	}
}
