/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: dilaouid <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2018/11/06 18:42:58 by dilaouid          #+#    #+#             */
/*   Updated: 2018/11/21 13:39:25 by dilaouid         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

int		ft_atoi(const char *nptr)
{
	int i;
	int neg;
	int nb;

	i = 0;
	neg = 1;
	nb = 0;
	while (nptr[i] == ' ' || nptr[i] == '\t'
			|| nptr[i] == '\n' || nptr[i] == '\r'
			|| nptr[i] == '\b' || nptr[i] == '\v'
			|| nptr[i] == '\f')
		i++;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg = -1;
		i++;
	}
	while ((nptr[i] >= '0' && nptr[i] <= '9') && nptr[i])
		nb = (nptr[i++] - '0') + (nb * 10);
	return (nb * neg);
}
