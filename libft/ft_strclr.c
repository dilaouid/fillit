/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strclr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:48:05 by dilaouid          #+#    #+#             */
/*   Updated: 2018/11/21 13:47:29 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	ft_strclr(char *s)
{
	size_t i;

	i = 0;
	if (s == NULL)
		return ;
	while (s[i])
		s[i++] = '\0';
}
