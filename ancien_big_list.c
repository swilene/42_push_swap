/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/16 12:21:09 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/18 18:59:53 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstpos(int nbr, t_list **lst)
{
	t_list	*tmp;
	int	pos;

	tmp = (*lst);
	pos = 0;
	while (tmp && nbr < tmp->nb)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

void	ft_movelst(t_list **lst, int pos, int size, int list)
{
	if (pos > 1 && pos <= size/2)
	{
		while (pos > 0)
		{
			ft_lstrotate(&(*lst), list);
			pos--;
		}
	}
	else if (pos > size/2 && pos < size)
	{
		while (pos < size)
		{
			ft_lstreverse_rotate(&(*lst), list);
			pos++;
		}
	}
}

void	ft_movelist_b(t_list **list_b, t_list *last_b, int size_b, int pos)
{
	if (size_b == 1 && (*list_b)->nb < (*list_b)->next->nb)
		ft_lstswap(&(*list_b), 2);
	if (size_b == 2)
	{
		if ((*list_b)->nb < last_b->nb)
			ft_lstrotate(&(*list_b), 2);
		if ((*list_b)->nb < (*list_b)->next->nb)
			ft_lstswap(&(*list_b), 2);
	}
	if (pos == 1)
		ft_lstswap(&(*list_b), 2);
	else if (pos == size_b)
		ft_lstrotate(&(*list_b), 2);
}

char	*ft_movelist_a(t_list **list_a, t_list **list_b, t_list *last_a)
{		
	t_list	*last_b;
	int	pos;
	int	size_b;
	
	last_a = ft_lstlast(*list_a);
	pos = 0;
	if ((*list_a)->nb > (*list_a)->next->nb)
		ft_lstswap(&(*list_a), 1);
	if ((*list_a)->nb > last_a->nb)
		ft_lstreverse_rotate(&(*list_a), 1);
	last_b = ft_lstlast(*list_b);
	size_b = ft_lstsize(*list_b);
	if (size_b > 2)
	{
		pos = ft_lstpos((*list_a)->nb, &(*list_b));
		ft_movelst(&(*list_b), pos, size_b, 2);
	}
	if (ft_lstpush_b(&(*list_a), &(*list_b)) == NULL)
		return (NULL);
	ft_movelist_b(&(*list_b), last_b, size_b, pos);
	return ("OK");
}

char	*ft_bigsize(t_list **list_a, t_list **list_b, int size_a)
{
	t_list	*last_a;

	last_a = NULL;
	while (size_a > 3)
	{
		if (ft_movelist_a(&(*list_a), &(*list_b), last_a) == NULL)
			return (NULL);
		size_a--;
	}
	ft_size3(&(*list_a));
	if ((*list_b)->nb > (*list_a)->nb)
		ft_lstrotate(&(*list_a), 1);
	while (*list_b)
	{
		if ((*list_b)->nb < (*list_a)->nb)
		{
			if (ft_lstpush_a(&(*list_b), &(*list_a)) == NULL)
				return (NULL);
		}
		else
			ft_lstrotate(&(*list_a), 1);
	}
	while (ft_checksorted(*list_a) == 0)
		ft_lstreverse_rotate(&(*list_a), 1);
	return ("OK");
}
