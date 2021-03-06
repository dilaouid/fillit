/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_sqrt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aibatyrb <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/07/06 10:12:49 by aibatyrb          #+#    #+#             */
/*   Updated: 2018/12/25 20:44:56 by aibatyrb         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_sqrt(int nb)
{
	int result;

	result = 1;
	if (nb == 0)
		return (0);
	while (result * result < nb)
		result++;
	if (nb % result == 0 && result * result == nb)
		return (result);
	return (result);
}
