/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnlen.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/21 15:15:43 by dilaouid          #+#    #+#             */
/*   Updated: 2018/11/21 15:16:08 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>

size_t		ft_strnlen(const char *s, size_t n)
{
	size_t i;

	i = 0;
	while (s[i] && n--)
		i++;
	return (i);
}
