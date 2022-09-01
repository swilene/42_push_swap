/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:52:26 by saguesse          #+#    #+#             */
/*   Updated: 2022/09/01 15:43:27 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	main(int argc, char **argv)
{
	t_list	*list_a;
	t_list	*list_b;
	int		check;

	if (argc == 1)
		return (1);
	list_a = NULL;
	list_b = NULL;
	check = ft_checkargs(argc, argv, &list_a);
	if (check == 1)
		return (ft_putstr_fd("Error\n", 2), 1);
	else if (check == 2)
		return (1);
	ft_pushswap(&list_a, &list_b);
	ft_dellist(&list_a);
	return (0);
}
