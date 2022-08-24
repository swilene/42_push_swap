/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:52:26 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/24 17:36:48 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	int		check;

	list_a = NULL;
	list_b = NULL;
	check = ft_checkargs(argc, argv, &list_a);
	if (argc == 1)
		return (1);
	if (check == 1)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	else if (check == 2)
	{
		ft_putstr_fd("\n", 2);
		return (1);
	}
	if (ft_pushswap(&list_a, &list_b) == NULL)
		return (1);
	printf("LIST A = \n");
	ft_lstprint(list_a);
	ft_dellist(&list_a);
	return (0);
}
