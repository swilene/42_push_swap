/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:51:08 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/18 19:00:27 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_size3(t_list **list_a)
{
	while (ft_checksorted(*list_a) != 1)
	{
		if ((*list_a)->nb < (*list_a)->next->next->nb)
			ft_lstswap(&(*list_a), 1);
		else if ((*list_a)->nb > (*list_a)->next->nb && (*list_a)->nb > (*list_a)->next->next->nb)
			ft_lstrotate(&(*list_a), 1);
		else if ((*list_a)->nb < (*list_a)->next->nb && (*list_a)->nb > (*list_a)->next->next->nb)
			ft_lstreverse_rotate(&(*list_a), 1);
	}
}

char	*ft_pushswap(t_list **list_a, t_list **list_b)
{
	int	size;

	size = ft_lstsize(*list_a);
	if (size == 1)
		write(1, "\n", 1);
	else if (size == 2)
		ft_lstswap(&(*list_a), 1);
	else if (size == 3)
		ft_size3(&(*list_a));
	else
	{
		if (ft_bigsize(&(*list_a), &(*list_b), size) == NULL)
			return (NULL);
	}
	write(1, "\n", 1);
	ft_lstprint(*list_a);
	return ("OK");
}
