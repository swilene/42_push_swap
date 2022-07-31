/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:41:55 by saguesse          #+#    #+#             */
/*   Updated: 2022/07/31 11:31:41 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	ft_atoi(const char *nptr)
{
	ssize_t	nb;
	size_t	i;
	int		neg;

	nb = 0;
	neg = 1;
	i = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
			neg *= -1;
		i++;
	}
	if (nptr[i] == '\0')
		return (2147483648);
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (2147483648);
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	return (nb * neg);
}
