/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/05 11:41:55 by saguesse          #+#    #+#             */
/*   Updated: 2022/07/21 16:32:30 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

ssize_t	ft_atoi(const char *nptr)
{
	ssize_t	nb;
	int	neg;
	size_t	i;

	nb = 0;
	neg = 1;
	i = 0;
	if (nptr[i] == '+' || nptr[i] == '-')
	{
		if (nptr[i] == '-')
		{
			if (nptr[1] == '\0')
				return (2147483648);
			neg *= -1;
		}
		i++;
	}
	while (nptr[i])
	{
		if (nptr[i] < '0' || nptr[i] > '9')
			return (2147483648);
		nb = nb * 10 + nptr[i] - '0';
		i++;
	}
	return (nb * neg);
}
