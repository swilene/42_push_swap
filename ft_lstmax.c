/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmax.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/30 22:55:51 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/30 23:05:11 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstmax(t_list *lst)
{
	t_list	*tmp;
	t_list	*max;

	tmp = lst;
	max = tmp;
	while (tmp)
	{
		if (max->nb < tmp->nb)
			max = tmp;
		tmp = tmp->next;
	}
	return (max);
}
