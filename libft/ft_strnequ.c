/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnequ.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:51:10 by dilaouid          #+#    #+#             */
/*   Updated: 2018/11/21 13:51:13 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <string.h>
#include <stdlib.h>

int				ft_strnequ(char const *s1, char const *s2, size_t n)
{
	int i;

	i = 0;
	if (s1 == NULL || s2 == NULL)
		return (0);
	while (s1[i] && s1[i] == s2[i] && i < (int)n)
	{
		if (s1[i] != s2[i])
			return (0);
		i++;
	}
	if (i < (int)n)
		return (s1[i] == s2[i]);
	return (1);
}
