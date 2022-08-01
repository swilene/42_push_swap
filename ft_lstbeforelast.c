/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstbeforelast.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 13:02:16 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/01 13:05:27 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

t_list	*ft_lstbeforelast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	else
	{
		while (lst->next->next != NULL)
			lst = lst->next;
	}
	return (lst);
}
