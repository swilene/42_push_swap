/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 17:28:39 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/21 19:49:48 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkreverse_sorted(t_list *lst)
{
	while (lst->next != NULL && lst->nb > lst->next->nb)
		lst = lst->next;
	if (lst->next == NULL)
		return (1);
	return (0);
}

char    *ft_bigsize(t_list **list_a, t_list **list_b, int size_a)
{
	t_list	*last_a;
	int	size_b;
	int	pos;
	int	min;

	min = ft_lstmin(*list_a);
	while (size_a > 3)
	{
		last_a = ft_lstlast(*list_a);
		size_b = ft_lstsize(*list_b);
		if ((*list_a)->nb > (*list_a)->next->nb)
			ft_lstswap(&(*list_a), 1);
		if ((*list_a)->nb > last_a->nb)
			ft_lstreverse_rotate(&(*list_a), 1);
		if (size_b > 3)
		{
			if (ft_checkreverse_sorted(*list_b) == 0)
				pos = ft_lstpos_reversesorted((*list_a)->nb, *list_b);
			else
				pos = ft_lstpos_reverse((*list_a)->nb, *list_b);
			if (pos > 1 && pos <= size_b/2)
			{
				while (pos > 0)
				{
					ft_lstrotate(&(*lst), list);
					pos--;
				}
			}
			else if (pos > size/2 && pos < size_b)
			{
				while (pos < size)
				{
					ft_lstreverse_rotate(&(*lst), list);
					pos++;
				}
			}
		}
		if (ft_lstpush_b(&(*list_a), &(*list_b)))
			return (NULL);
		if (pos == 1)
			ft_lstswap(&(*list_a), 1);
		if (size == )
		size_a--;
	}
	return ("OK");
}
