/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:57:48 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/01 17:44:41 by saguesse         ###   ########.fr       */
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
		(*list_a) = ft_lstnew(nb, (*list_a));
		if (list_a == NULL)
			return (NULL);
	}
	else
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return (NULL);
		tmp = (*list_a);
		ft_lstadd_back(&tmp, new, nb);
	}
	return ("OK");
}

char	*check_args(int argc, char **argv)
{
	int		i;
	t_list	*list_a;
	t_list	*tmp;

	i = 1;
	list_a = NULL;
	while (i < argc)
	{
		if (ft_lstlist_a(argv, i, &list_a) == NULL)
		{
			if (list_a != NULL)
				ft_dellist(&list_a);
			return (NULL);
		}
		i++;
	}
	tmp = list_a;
	if (ft_checkdoubles(i - 1, &tmp) == 1)
		return (ft_dellist(&list_a), NULL);
	tmp = list_a;
	ft_lstprint(tmp);
	ft_swap_a(&list_a);
	tmp = list_a;
	ft_lstprint(tmp);
	ft_rotate_a(&list_a);
	tmp = list_a;
	ft_lstprint(tmp);
	ft_reverse_rotate_a(&list_a);
	tmp = list_a;
	ft_lstprint(tmp);
	return ("OK");
}
