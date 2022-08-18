/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:51:29 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/17 19:00:56 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_lstnew(int nbr, t_list **head)
{
	(*head) = malloc(sizeof(t_list));
	if (!(*head))
		return (ft_dellist(head), NULL);
	(*head)->next = NULL;
	(*head)->nb = nbr;
	return ("OK");
}
