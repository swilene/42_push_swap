/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:40:59 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/24 15:40:14 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstprint(t_list *lst)
{
	while (lst)
	{
		ft_putnbr(lst->nb);
		ft_putchar('\n');
		ft_putstr_fd("index = ", 1);
		ft_putnbr(lst->index);
		ft_putchar('\n');
		ft_putchar('\n');
		lst = lst->next;
	}
}
