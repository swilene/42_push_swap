/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/08 14:15:11 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/17 19:01:40 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_lstadd_front(t_list **lst, int nbr)
{
	t_list	*new;

	new = malloc(sizeof(t_list));
	if (!new)
		return (ft_dellist(lst), NULL);
	if ((*lst) == NULL)
	{
		if (ft_lstnew(nbr, &(*lst)) == NULL)
			return (NULL);
	}
	new->next = (*lst);
	new->nb = nbr;
	(*lst) = new;
	return ("OK");
}
