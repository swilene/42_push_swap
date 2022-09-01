/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstnew.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 09:51:29 by saguesse          #+#    #+#             */
/*   Updated: 2022/09/01 10:59:26 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_lstnew(int nbr, t_list **head)
{
	(*head) = malloc(sizeof(t_list));
	if (!(*head))
		return (NULL);
	(*head)->next = NULL;
	(*head)->nb = nbr;
	(*head)->index = 0;
	return ("OK");
}
