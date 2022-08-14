/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/13 10:51:08 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/14 21:23:47 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstpos(int nbr, t_list **lst)
{
	t_list	*tmp;
	int	pos;

	tmp = (*lst);
	pos = 0;
	while (nbr < tmp->nb)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

void	ft_bigsize(t_list **list_a, t_list **list_b, int size_a)
{
	t_list	*last_a;
	t_list	*last_b;
	int	pos;
	int	size_b;
	
	while (size_a > 3)
	{
		//printf("1er = %d\n", (*list_a)->nb);
		//printf("2eme = %d\n", (*list_a)->next->nb);
		//printf("dernier = %d\n", last_a->nb);
		printf("debut list b =\n");
		ft_lstprint(*list_b);
		printf("debut list a =\n");
		ft_lstprint(*list_a);
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
			if ((*list_a)->nb < (*list_b)->nb && (*list_a)->nb > last_b->nb)
			{
				pos = ft_lstpos((*list_a)->nb, &(*list_b));
				if (pos < size_b/2)
				{
					while (pos > 0)
					{
						ft_lstrotate(&(*list_b), 2);
						pos--;
					}
				}
				else if (pos > size_b/2)
				{
					while (pos > 0)
					{
						ft_lstreverse_rotate(&(*list_b), 2);
						pos--;
					}
				}
			}
		}
		ft_lstpush_b(&(*list_a), &(*list_b));
		if (pos == 1)
			ft_lstswap(&(*list_b), 2);
		if (ft_lstsize(*list_b) > 2)
		{
			if ((*list_b)->nb < last_b->nb)
				ft_lstrotate(&(*list_b), 2);
		}
		size_a--;
	}
	printf("fin list b =\n");
	ft_lstprint(*list_b);
	printf("fin list a =\n");
	ft_lstprint(*list_a);
}

void	ft_size5(t_list **list_a, t_list **list_b, int size)
{
	int	min;
	int	index;
	t_list	*tmp;

	tmp = (*list_a);
	min = (*list_a)->nb;
	while (tmp)
	{
		if (min > tmp->nb)
			min = tmp->nb;
		tmp = tmp->next;
	}
	index = ft_lstindex(&(*list_a), min);
	while (min != (*list_a)->nb)
	{
		if (index < size)
			ft_lstrotate(&(*list_a), 1);
		else
			ft_lstreverse_rotate(&(*list_a), 1);
	}
	ft_lstpush_b(&(*list_a), &(*list_b));
}

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
	if (size == 2)
		ft_lstswap(&(*list_a), 1);
	if (size == 3)
		ft_size3(&(*list_a));
	if (size == 5)
	{
		ft_size5(&(*list_a), &(*list_b), size - 1);
		ft_size5(&(*list_a), &(*list_b), size - 2);
		ft_size3(&(*list_a));
		while (*list_b)
			ft_lstpush_a(&(*list_b), &(*list_a));
	}
	if (size > 5)
		ft_bigsize(&(*list_a), &(*list_b), size);
	//ft_lstprint(*list_a);
	return ("OK");
}
