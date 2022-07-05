/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:52:26 by saguesse          #+#    #+#             */
/*   Updated: 2022/07/05 12:45:54 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkargv(char *str)
{
	int	j;

	j = 0;
	while (str[j])
	{
		printf("str[%d] = %c\n", j, str[j]);
		if (str[j] <= '0' && str[j] >= '9' && str[j] != ' ')
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
		printf("%d\n", ft_checkargv(argv[i]));
		i++;
	}
	return (0);
}
