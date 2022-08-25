/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:29:56 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/25 12:04:00 by saguesse         ###   ########.fr       */
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

void	ft_lstpush(t_list **pull, t_list **push, int list)
{
	t_list	*tmp_pull;
	t_list	*tmp_push;

	if ((*pull) == NULL)
		return ;
	if ((*push) == NULL)
	{
		tmp_pull = (*pull);
		(*pull) = (*pull)->next;
		(*push) = tmp_pull;
		(*push)->next = NULL;
	}
	else
	{
		tmp_pull = (*pull);
		(*pull) = (*pull)->next;
		tmp_push = (*push);
		(*push) = tmp_pull;
		(*push)->next = tmp_push;
	}
	if (list == 1)
		ft_putstr_fd("pa\n", 1);
	else
		ft_putstr_fd("pb\n", 1);
}
