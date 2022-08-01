/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:29:56 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/01 15:16:55 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **lst)
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
	ft_putstr_fd("\nsa\n", 1);
}

void	ft_rotate_a(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*second;

	if ((*lst) == NULL || (*lst)->next == NULL)
		return ;
	if ((*lst)->next->next == NULL)
		ft_swap_a(&(*lst));
	second = (*lst)->next;
	tmp = (*lst);
	last = ft_lstlast(tmp);
	last->next = tmp;
	tmp->next = NULL;
	(*lst) = second;
	ft_putstr_fd("\nra\n", 1);
}

void	ft_reverse_rotate_a(t_list **lst)
{
	t_list	*tmp;
	t_list	*last;
	t_list	*before_last;

	if ((*lst) == NULL || (*lst)->next == NULL)
		return ;
	if ((*lst)->next->next == NULL)
		ft_swap_a(&(*lst));
	tmp = (*lst);
	last = ft_lstlast(tmp);
	tmp = (*lst);
	before_last = ft_lstbeforelast(tmp);
	(*lst) = last;
	(*lst)->next = tmp;
	before_last->next = NULL;
	ft_putstr_fd("\nrra\n", 1);
}

void	ft_push_a()
{
	

	ft_putstr_fd("\npa\n", 1);
}
