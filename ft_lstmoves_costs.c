/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmoves_costs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:32:36 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/25 17:05:11 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstmoves_costs(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;
	int	size_b;
	int	size_a;

	tmp = (*list_b);
	size_b = ft_lstsize(*list_b);
	size_a = ft_lstsize(*list_a);
	while (tmp)
	{
		if (tmp->pos <= size_b / 2)
			tmp->move_b = tmp->pos;
		else
			tmp->move_b = -(size_b - tmp->pos);
		if (tmp->pos_wanted <= size_a / 2)
			tmp->move_a = tmp->pos_wanted;
		else
			tmp->move_a = -(size_a - tmp->pos_wanted + 1);
		tmp = tmp->next;
	}
}
