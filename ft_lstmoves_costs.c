/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmoves_costs.c                                :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/25 15:32:36 by saguesse          #+#    #+#             */
/*   Updated: 2022/09/01 15:23:20 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

//	find the element with the smallest amount of moves
t_list	*ft_best_move(t_list *list_b)
{
	int		move_min;
	int		index_min;
	t_list	*tmp;

	tmp = list_b;
	move_min = abs(tmp->move_a) + abs(tmp->move_b);
	index_min = tmp->index;
	while (tmp)
	{
		if (move_min > abs(tmp->move_a) + abs(tmp->move_b))
		{
			move_min = abs(tmp->move_a) + abs(tmp->move_b);
			index_min = tmp->index;
		}
		tmp = tmp->next;
	}
	tmp = list_b;
	while (tmp && index_min != tmp->index)
		tmp = tmp->next;
	return (tmp);
}

//	move just a (ra and rra)
void	ft_moves_a(t_list **list_a, t_list *lst)
{
	if (lst->move_a < 0)
	{
		while (lst->move_a != 0)
		{
			ft_lstreverse_rotate(list_a, 1);
			lst->move_a++;
		}
	}
	else if (lst->move_a > 0)
	{
		while (lst->move_a != 0)
		{
			ft_lstrotate(list_a, 1);
			lst->move_a--;
		}
	}
}

//	move just b (rb and rrb)
void	ft_moves_b(t_list **list_b, t_list *lst)
{
	if (lst->move_b < 0)
	{
		while (lst->move_b != 0)
		{
			ft_lstreverse_rotate(list_b, 2);
			lst->move_b++;
		}
	}
	else if (lst->move_b > 0)
	{
		while (lst->move_b != 0)
		{
			ft_lstrotate(list_b, 2);
			lst->move_b--;
		}
	}
}

//	move a and b together (rr and rrr)
//	push the element with the smallest number of moves
void	ft_push_min(t_list **list_a, t_list **list_b, t_list *lst)
{
	if (lst->move_b < 0 && lst->move_a < 0)
	{
		while (lst->move_b != 0 && lst->move_a != 0)
		{
			ft_lstreverse_rotate(list_b, 3);
			ft_lstreverse_rotate(list_a, 3);
			ft_putstr_fd("rrr\n", 1);
			lst->move_b++;
			lst->move_a++;
		}
	}
	else if (lst->move_b > 0 && lst->move_a > 0)
	{
		while (lst->move_b != 0 && lst->move_a != 0)
		{
			ft_lstrotate(list_b, 3);
			ft_lstrotate(list_a, 3);
			ft_putstr_fd("rr\n", 1);
			lst->move_b--;
			lst->move_a--;
		}
	}
	ft_moves_b(list_b, lst);
	ft_moves_a(list_a, lst);
	ft_lstpush(list_b, list_a, 1);
}

//	calculate how many moves we need to move each number of b
//		at the top of b
//		at the right place in a 
void	ft_lstmoves_costs(t_list **list_a, t_list **list_b)
{
	t_list	*tmp;
	int		size_b;
	int		size_a;

	tmp = (*list_b);
	size_b = ft_lstsize(*list_b);
	size_a = ft_lstsize(*list_a);
	while (tmp)
	{
		if (tmp->pos <= size_b / 2)
			tmp->move_b = tmp->pos;
		else
			tmp->move_b = -(size_b - tmp->pos);
		if (tmp->pos_wanted > 0 && tmp->pos_wanted <= size_a / 2)
			tmp->move_a = tmp->pos_wanted;
		else if (tmp->pos_wanted > size_a / 2 && tmp->pos_wanted < size_a)
			tmp->move_a = -(size_a - tmp->pos_wanted);
		else
			tmp->move_a = 0;
		tmp = tmp->next;
	}
	ft_push_min(list_a, list_b, ft_best_move(*list_b));
}
