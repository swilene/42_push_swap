/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmin.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/19 15:04:22 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/24 15:11:27 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmin(t_list *lst)
{
	t_list	*tmp;
	t_list	*min;

	tmp = lst;
	min = tmp;
	while (tmp)
	{
		if (min->nb > tmp->nb)
			min = tmp;
		tmp = tmp->next;
	}
	return (min);
}
