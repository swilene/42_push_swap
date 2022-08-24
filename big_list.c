/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   big_list.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/24 11:17:32 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/24 17:48:15 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

char	*ft_bigsize(t_list **list_a, t_list **list_b, int size_a)
{
	int	med;

	med = size_a / 2;
	printf("med = %d\n", med);
	while (size_a > med)
	{
		if ((*list_a)->index <= med)
		{
			//if (ft_lstpush(list_a, list_b, 2) == NULL)
			//	return (NULL);
			ft_lstpush(list_a, list_b, 2);
		}
		else
			ft_lstrotate(list_a, 1);
		size_a = ft_lstsize(*list_a);
	}
	while (size_a > 3)
	{
		//if (ft_lstpush(list_a, list_b, 2) == NULL)
		//	return (NULL);
		ft_lstpush(list_a, list_b, 2);
		size_a--;
	}
	printf("LIST B = \n");
	ft_lstprint(*list_b);
	return ("OK");
}
