/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:57:48 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/26 09:41:28 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

int	ft_checkdoubles(int size, t_list **lst)
{
	int		nbr;
	t_list	*tmp;

	while (size > 0)
	{
		nbr = (*lst)->nb;
		tmp = (*lst)->next;
		while (tmp)
		{
			if (tmp->nb == nbr)
				return (1);
			tmp = tmp->next;
		}
		size--;
		(*lst) = (*lst)->next;
	}
	return (0);
}

char	*ft_lstlist_a(char **argv, int i, t_list **list_a)
{
	ssize_t	nb;
	t_list	*new;
	t_list	*tmp;

	nb = ft_atoi(argv[i]);
	if (nb < INT_MIN || nb > INT_MAX)
		return (NULL);
	if (i == 1)
	{
		if (ft_lstnew(nb, list_a) == NULL)
			return (NULL);
	}
	else
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return (ft_dellist(list_a), NULL);
		tmp = (*list_a);
		ft_lstadd_back(&tmp, new, nb);
	}
	return ("OK");
}

int	ft_checksorted(t_list *lst)
{
	while (lst->next != NULL && lst->nb < lst->next->nb)
		lst = lst->next;
	if (lst->next != NULL)
		return (1);
	return (0);
}

int	ft_checkargs(int argc, char **argv, t_list **list_a)
{
	int		i;
	t_list	*tmp;

	i = 1;
	(*list_a) = NULL;
	while (i < argc)
	{
		if (ft_lstlist_a(argv, i, list_a) == NULL)
		{
			if ((*list_a) != NULL)
				ft_dellist(list_a);
			return (1);
		}
		i++;
	}
	tmp = (*list_a);
	if (ft_checkdoubles(i - 1, &tmp) == 1)
		return (ft_dellist(list_a), 1);
	tmp = (*list_a);
	if (ft_checksorted(tmp) == 0)
		return (2);
	return (0);
}
