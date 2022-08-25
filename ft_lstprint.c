/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstprint.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/01 10:40:59 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/25 16:40:04 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_lstprint_a(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	ft_putstr_fd("valeur\t\t", 1);
	while (tmp)
	{
		ft_putchar(' ');
		ft_putnbr(tmp->nb);
		ft_putchar('\t');
		tmp = tmp->next;
	}
	tmp = lst;
	ft_putstr_fd("\nindex\t\t", 1);
	while (tmp)
	{
		ft_putchar('[');
		ft_putnbr(tmp->index);
		ft_putchar(']');
		ft_putchar('\t');
		tmp = tmp->next;
	}
	tmp = lst;
	ft_putstr_fd("\nposition\t", 1);
	while (tmp)
	{
		ft_putchar('<');
		ft_putnbr(tmp->pos);
		ft_putchar('>');
		ft_putchar('\t');
		tmp = tmp->next;
	}
	ft_putstr_fd("\n", 1);
}

void	ft_lstprint_b(t_list *lst)
{
	t_list	*tmp;

	tmp = lst;
	ft_putstr_fd("valeur\t\t", 1);
	while (tmp)
	{
		ft_putchar(' ');
		ft_putnbr(tmp->nb);
		ft_putchar('\t');
		tmp = tmp->next;
	}
	tmp = lst;
	ft_putstr_fd("\nindex\t\t", 1);
	while (tmp)
	{
		ft_putchar('[');
		ft_putnbr(tmp->index);
		ft_putchar(']');
		ft_putchar('\t');
		tmp = tmp->next;
	}
	tmp = lst;
	ft_putstr_fd("\nposition\t", 1);
	while (tmp)
	{
		ft_putchar('<');
		ft_putnbr(tmp->pos);
		ft_putchar('>');
		ft_putchar('\t');
		tmp = tmp->next;
	}
	tmp = lst;
	ft_putstr_fd("\nposition cible\t", 1);
	while (tmp)
	{
		ft_putchar('(');
		ft_putnbr(tmp->pos_wanted);
		ft_putchar(')');
		ft_putchar('\t');
		tmp = tmp->next;
	}
	tmp = lst;
	ft_putstr_fd("\nmove b\t\t", 1);
	while (tmp)
	{
		ft_putchar(' ');
		ft_putnbr(tmp->move_b);
		ft_putchar('\t');
		tmp = tmp->next;
	}
	tmp = lst;
	ft_putstr_fd("\nmove a\t\t", 1);
	while (tmp)
	{
		ft_putchar(' ');
		ft_putnbr(tmp->move_a);
		ft_putchar('\t');
		tmp = tmp->next;
	}
	ft_putstr_fd("\n", 1);
	ft_putstr_fd("\n", 1);
}
