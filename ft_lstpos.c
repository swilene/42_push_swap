/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstpos.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 18:10:24 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/21 19:09:05 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstpos_sorted(int nbr, t_list *list_a)
{
	t_list	*tmp;
	int	pos;

	tmp = list_a;
	pos = 0;
	while (tmp && nbr > tmp->nb)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}	
int	ft_lstpos(int nbr, t_list *list_a)
{
	t_list	*tmp;
	int	pos;

	tmp = list_a;
	pos = 0;
	while (tmp && nbr > tmp->nb && nbr < tmp->nbr)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}	
int	ft_lstpos_reversesorted(int nbr, t_list *list_b)
{
	t_list	*tmp;
	int	pos;

	tmp = list_b;
	pos = 0;
	while (tmp && nbr > tmp->nb)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}

int	ft_lstpos_reverse(int nbr, t_list *list_b)
{
	t_list	*tmp;
	int	pos;

	tmp = list_b;
	pos = 0;
	while (tmp && nbr < tmp->nb && nbr > tmp->next->nb)
	{
		pos++;
		tmp = tmp->next;
	}
	return (pos);
}	
