/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower_ultimate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/07 17:30:40 by dilaouid          #+#    #+#             */
/*   Updated: 2018/11/21 14:07:35 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char		*ft_tolower_ultimate(char *s)
{
	int i;

	i = 0;
	while (s[i])
	{
		if (ft_isupper(s[i]) == 1)
			ft_tolower(s[i]);
		i++;
	}
	return (s);
}
