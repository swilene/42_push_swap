/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_back.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/20 10:16:52 by saguesse          #+#    #+#             */
/*   Updated: 2022/07/30 10:45:13 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstadd_back(t_list **lst, t_list *new, int nbr)
{
	t_list	*last;

	if ((*lst) == NULL)
		(*lst) = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
	}
	new->nb = nbr;
	new->next = NULL;
}
