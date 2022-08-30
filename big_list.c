/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:17:32 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/30 23:20:24 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_push_to_a(t_list **list_a, t_list **list_b)
{
	int	min;

	while (*list_b)
	{
		ft_lstpos(list_a, list_b);
		ft_lstpos_wanted(*list_a, *list_b);
		ft_lstmoves_costs(list_a, list_b);
	}
	min = ft_lstmin(*list_a)->index;
	while (ft_checksorted(*list_a) != 0)
	{
		if (min <= ft_lstsize(*list_a))
			ft_lstrotate(list_a, 1);
		else
			ft_lstrotate(list_a, 1);
	}
}

void	ft_bigsize(t_list **list_a, t_list **list_b, int size_a)
{
	int	med;
	int	modulo;

	med = size_a / 2;
	modulo = size_a % 2;
	if (modulo != 0)
		med++;
	while (size_a != med)
	{
		if (modulo != 0 && (*list_a)->index < med)
			ft_lstpush(list_a, list_b, 2);
		else if (modulo == 0 && (*list_a)->index <= med)
			ft_lstpush(list_a, list_b, 2);
		else
			ft_lstrotate(list_a, 1);
		size_a = ft_lstsize(*list_a);
	}
	while (size_a > 3)
	{
		ft_lstpush(list_a, list_b, 2);
		size_a = ft_lstsize(*list_a);
	}
	ft_size3(list_a);
	ft_push_to_a(list_a, list_b);
}
