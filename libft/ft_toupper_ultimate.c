/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_toupper_ultimate.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/16 18:13:17 by dilaouid          #+#    #+#             */
/*   Updated: 2018/11/21 13:55:10 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_toupper_ultimate(char *str)
{
	int i;

	i = 0;
	while (str[i])
	{
		if (ft_islower(str[i]) == 1)
			ft_toupper(str[i]);
		i++;
	}
	return (str);
}
