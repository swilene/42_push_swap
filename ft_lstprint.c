/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:40:59 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/08 14:56:37 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstprint(t_list *lst)
{
	while (lst)
	{
		ft_putnbr(lst->nb);
		ft_putchar('\n');
		lst = lst->next;
	}
	//ft_putstr_fd("-\n", 1);
	//ft_putstr_fd(" a \n", 1);
}
