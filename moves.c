/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:29:56 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/21 17:52:56 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstswap(t_list **lst, int list)
{
	t_list	*tmp;
	t_list	*third;

	if ((*lst) == NULL || (*lst)->next == NULL)
		return ;
	third = (*lst)->next->next;
	tmp = (*lst);
	(*lst) = (*lst)->next;
	(*lst)->next = tmp;
	tmp->next = third;
	if (list == 1)
		ft_putstr_fd("sa\n", 1);
	else
		ft_putstr_fd("sb\n", 1);
}

void	ft_lstrotate(t_list **lst, int list)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*second;

	if ((*lst) == NULL || (*lst)->next == NULL)
		return ;
	if ((*lst)->next->next == NULL)
		ft_lstswap(&(*lst), list);
	second = (*lst)->next;
	tmp = (*lst);
	last = ft_lstlast(tmp);
	last->next = tmp;
	tmp->next = NULL;
	(*lst) = second;
	if (list == 1)
		ft_putstr_fd("ra\n", 1);
	else
		ft_putstr_fd("rb\n", 1);
}

void	ft_lstreverse_rotate(t_list **lst, int list)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*before_last;

	if ((*lst) == NULL || (*lst)->next == NULL)
		return ;
	if ((*lst)->next->next == NULL)
		ft_lstswap(&(*lst), list);
	tmp = (*lst);
	last = ft_lstlast(tmp);
	tmp = (*lst);
	before_last = ft_lstbeforelast(tmp);
	(*lst) = last;
	(*lst)->next = tmp;
	before_last->next = NULL;
	if (list == 1)
		ft_putstr_fd("rra\n", 1);
	else
		ft_putstr_fd("rrb\n", 1);
}

char	*ft_lstpush_b(t_list **list_a, t_list **list_b)
{
	if ((*list_a) == NULL)
		return ("vide");
	if ((*list_b) == NULL)
	{
		if (ft_lstnew((*list_a)->nb, &(*list_b)) == NULL)
			return (NULL);
	}
	else if (ft_lstadd_front(&(*list_b), (*list_a)->nb) == NULL)
		return (ft_dellist(list_a), NULL);
	ft_lstdelone(&(*list_a));
	ft_putstr_fd("pb\n", 1);
	return ("OK");
}

char	*ft_lstpush_a(t_list **list_b, t_list **list_a)
{
	if ((*list_b) == NULL)
		return ("vide");
	if ((*list_a) == NULL)
	{
		if (ft_lstnew((*list_b)->nb, &(*list_a)) == NULL)
			return (NULL);
	}
	else if (ft_lstadd_front(&(*list_a), (*list_b)->nb) == NULL)
		return (ft_dellist(list_b), NULL);
	ft_lstdelone(&(*list_b));
	ft_putstr_fd("pa\n", 1);
	return ("OK");
}
