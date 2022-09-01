/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:40:57 by saguesse          #+#    #+#             */
/*   Updated: 2022/09/01 13:00:05 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	calculate the position wanted of an element if list a is not sorted
int	ft_lista_pos(int index, t_list *list_a, int pos)
{
	t_list	*tmp;
	t_list	*min_a;
	t_list	*max_a;

	tmp = list_a;
	min_a = ft_lstmin(list_a);
	max_a = ft_lstmax(list_a);
	if (index < min_a->index)
		pos = min_a->pos;
	else if (index > max_a->index)
		pos = max_a->pos + 1;
	else
	{
		while (tmp->next != NULL && !(index > tmp->index
				&& index < tmp->next->index))
			tmp = tmp->next;
		pos = tmp->pos + 1;
	}
	if (pos == ft_lstsize(list_a))
		pos = 0;
	return (pos);
}

//	calculate the position wanted of an element if list a is sorted
int	ft_lista_possorted(int index, t_list *list_a, int pos)
{
	t_list	*tmp;

	tmp = list_a;
	while (tmp && index > tmp->index)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

//	calculate the position wanted of each element of b in a
void	ft_lstpos_wanted(t_list *list_a, t_list *list_b)
{
	t_list	*tmp;

	tmp = list_b;
	while (tmp)
	{
		if (ft_checksorted(list_a) == 0)
			tmp->pos_wanted = ft_lista_possorted(tmp->index, list_a, 0);
		else
			tmp->pos_wanted = ft_lista_pos(tmp->index, list_a, 0);
		tmp = tmp->next;
	}
}

//	calculate the position of each number in both lists 
//		(first element is 0)
void	ft_lstpos(t_list **list_a, t_list **list_b)
{
	int		pos;
	t_list	*tmp;

	pos = 0;
	tmp = (*list_a);
	while (tmp)
	{
		tmp->pos = pos;
		pos++;
		tmp = tmp->next;
	}
	pos = 0;
	tmp = (*list_b);
	while (tmp)
	{
		tmp->pos = pos;
		pos++;
		tmp = tmp->next;
	}
}
