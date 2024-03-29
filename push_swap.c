/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:51:08 by saguesse          #+#    #+#             */
/*   Updated: 2022/09/01 17:23:14 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstindex(t_list *lst, int size)
{
	t_list	*tmp;
	t_list	*min;
	int		i;

	min = ft_lstmin(lst);
	min->index = 1;
	tmp = lst;
	i = 2;
	while (i <= size)
	{
		tmp = lst;
		min = tmp;
		while (min && min->index != 0)
			min = min->next;
		while (tmp)
		{
			if (min->nb > tmp->nb && tmp->index == 0)
				min = tmp;
			tmp = tmp->next;
		}
		min->index = i;
		i++;
	}
}

void	ft_size3(t_list **list_a)
{
	while (ft_checksorted(*list_a) != 0)
	{
		if ((*list_a)->nb < (*list_a)->next->next->nb)
			ft_lstswap(list_a, 1);
		else if ((*list_a)->nb > (*list_a)->next->nb
			&& (*list_a)->nb > (*list_a)->next->next->nb)
			ft_lstrotate(list_a, 1);
		else if ((*list_a)->nb < (*list_a)->next->nb
			&& (*list_a)->nb > (*list_a)->next->next->nb)
			ft_lstreverse_rotate(list_a, 1);
	}
}

void	ft_size4(t_list **list_a, t_list **list_b)
{
	ft_lstpush(list_a, list_b, 2);
	ft_size3(list_a);
	if ((*list_b)->nb > ft_lstbeforelast(*list_a)->nb
		&& (*list_b)->nb < ft_lstlast(*list_a)->nb)
		ft_lstreverse_rotate(list_a, 1);
	ft_lstpush(list_b, list_a, 1);
	if ((*list_a)->nb > ft_lstlast(*list_a)->nb)
	{
		ft_lstrotate(list_a, 1);
		if ((*list_a)->nb > ft_lstlast(*list_a)->nb)
			ft_lstrotate(list_a, 1);
	}
	else if ((*list_a)->nb > (*list_a)->next->nb)
		ft_lstswap(list_a, 1);
}

void	ft_pushswap(t_list **list_a, t_list **list_b)
{
	int	size;

	size = ft_lstsize(*list_a);
	if (size == 1)
		write(1, "\n", 1);
	else if (size == 2)
		ft_lstswap(list_a, 1);
	else if (size == 3)
		ft_size3(list_a);
	else if (size == 4)
		ft_size4(list_a, list_b);
	else
	{
		ft_lstindex(*list_a, size);
		ft_bigsize(list_a, list_b, size);
	}
}
