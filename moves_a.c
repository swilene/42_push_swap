/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   moves_a.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/18 16:29:56 by saguesse          #+#    #+#             */
/*   Updated: 2022/07/31 18:41:40 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_swap_a(t_list **lst)
{
	t_list	*tmp;

	if ((*lst) == NULL || (*lst)->next == NULL)
		return ;
	tmp = (*lst);
	(*lst) = (*lst)->next;
	(*lst)->next = tmp;
	printf("1er = %d\n", (*lst)->nb);
	printf("2eme = %d\n", (*lst)->next->nb);
}
/*
ft_push_a()
{

}

ft_rotate_a()
{

}

ft_reverse_rotate_a()
{

}*/
