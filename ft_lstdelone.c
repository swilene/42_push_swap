/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:47:16 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/15 12:28:21 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstdelone(t_list **lst)
{
	t_list	*tmp;

	if ((*lst) == NULL)
		return ;
	tmp = (*lst)->next;
	free(*lst);
	(*lst) = tmp;
}
