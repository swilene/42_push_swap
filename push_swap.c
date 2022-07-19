/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:52:26 by saguesse          #+#    #+#             */
/*   Updated: 2022/07/19 18:32:49 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkargv(char *str)
{
	int	i;	

	i = 0;
	while (str[i])
	{
		if ((str[i] < '0' || str[i] > '9') && str[i] != ' ' && str[i] != '-' && str[i] != '+')
			return (1);
		i++;
	}
	return (0);
}

int	main(int argc, char **argv)
{
	int		i;
	int		j;
	char	***nbr;
	ssize_t	nb;

	i = 1;
	j = 0;
	if (argc == 1)
		return (1);
	nbr = malloc(sizeof(nbr) * argc);
	while (i < argc)
	{
		if (ft_checkargv(argv[i]) == 1)
		{
			ft_putstr_fd("Error\n", 1);
			return (1);
		}
		nbr[j] = ft_split(argv[i], ' ');
		i++;
		j++;
	}
	i = 0;
	j = 0;
	while (j < (argc - 1))
	{
		while (nbr[j][i] != NULL)
		{
			nb = ft_atoi(nbr[j][i]);
			printf("%zd\n", nb);
			if (nb < INT_MIN || nb > INT_MAX)
			{
				ft_putstr_fd("Error\n", 1);
				return (1);
			}
			i++;
		}
		j++;
	}
	return (0);
}
