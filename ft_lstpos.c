/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 11:40:57 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/25 16:50:15 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstposmin_a(t_list *list_a, int pos)
{
	t_list	*tmp;
	int		min_a;

	tmp = list_a;
	min_a = ft_lstmin(list_a)->index;
	while (tmp->nb != min_a)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

int	ft_lista_pos(int index, t_list *list_a, int pos)
{
	t_list	*tmp;
	int		min_a;

	tmp = list_a;
	min_a = ft_lstmin(list_a)->index;
	if (index < min_a)
	{
		while (tmp && tmp->index != min_a)
		{
			pos++;
			tmp = tmp->next;
		}
	}
	else
	{
		while (tmp->next != NULL && !(index > tmp->index && index < tmp->next->index))
		{
			pos++;
			tmp = tmp->next;
		}
	}
	return (pos);
}

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

void	ft_lstpos(t_list *list_a, t_list *list_b)
{
	int		pos;
	t_list	*tmp;

	pos = 0;
	tmp = list_a;
	while (tmp)
	{
		tmp->pos = pos;
		pos++;
		tmp = tmp->next;
	}
	if (list_b == NULL)
		return ;
	pos = 0;
	tmp = list_b;
	while (tmp)
	{
		tmp->pos = pos;
		pos++;
		tmp = tmp->next;
	}
}
