/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstindex.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/14 10:59:17 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/14 11:03:06 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_lstindex(t_list **lst, int nbr)
{
	int	index;
	t_list	*tmp;

	index = 1;
	tmp = (*lst);
	while (tmp->nb != nbr)
	{
		index++;
		tmp = tmp->next;
	}
	return (index);
}
