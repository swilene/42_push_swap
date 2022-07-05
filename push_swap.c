/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:52:26 by saguesse          #+#    #+#             */
/*   Updated: 2022/07/05 17:13:57 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkargv(char *str)
{
	int	j;

	j = 0;

	while (str[j])
	{
		if ((str[j] <= '0' || str[j] >= '9') && str[j] != ' ' && str[j] != '-'
			&& str[j] != '-' && str[j] != '-' && str[j] != '-')
			return (1);
		j++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int	i;

	i = 1;
	if (argc == 1)
	{
		ft_putstr_fd("Error\n", 1);
		return (1);
	}
	while (i < argc)
	{
		if (ft_checkargv(argv[i]) == 1)
		{
			ft_putstr_fd("Error\n", 1);
			return (1);
		}
		i++;
	}
	return (0);
}
