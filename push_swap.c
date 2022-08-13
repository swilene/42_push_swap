/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:51:08 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/13 18:09:19 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_size5(t_list **list_a, t_list **list_b)
{
	int	min;
	int	index;
	t_list	*tmp;

	tmp = (*list_a);
	min = (*lst_a)->nb;
	index = 1;
	while (*list_a)
	{
		if (min > tmp->nb)
			min = tmp->nb;
		tmp = tmp->next;
		index++;
	}
	tmp = (*list_a);
	while (min != tmp->nb)
	{
		if (index < 4)
			ft_lstrotate(tmp);
		else
			ft_lstreverse_rotate(tmp);
		tmp = tmp->next;
	}
	ft_lstpush_b(&tmp, &(*list_b));

}

void	ft_size3(t_list **list_a)
{
	while (ft_checksorted(*list_a) != 1)
	{
		if ((*list_a)->nb < (*list_a)->next->next->nb)
			ft_lstswap(&(*list_a));
		else if ((*list_a)->nb > (*list_a)->next->nb && (*list_a)->nb > (*list_a)->next->next->nb)
			ft_lstrotate(&(*list_a));
		else if ((*list_a)->nb < (*list_a)->next->nb && (*list_a)->nb > (*list_a)->next->next->nb)
			ft_lstreverse_rotate(&(*list_a));
	}
}

char	*ft_pushswap(t_list **list_a, t_list **list_b)
{
	int	size;

	size = ft_lstsize(*list_a);
	if (size == 1)
		write(1, "\n", 1);
	if (size == 2)
		ft_lstswap(&(*list_a));
	if (size == 3)
		ft_size3(&(*list_a));
	if (size == 5)
		ft_size5(&(*list_a), &(*list_b));
	ft_lstprint(*list_a);
	return ("OK");
}
