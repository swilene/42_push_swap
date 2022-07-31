/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:57:48 by saguesse          #+#    #+#             */
/*   Updated: 2022/07/31 18:42:05 by saguesse         ###   ########.fr       */
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

char	*check_args(int argc, char **argv)
{
	int		i;
	ssize_t	nb;
	t_list	*new;
	t_list	*head;
	t_list	*tmp;

	i = 1;
	head = NULL;
	while (i < argc)
	{
		nb = ft_atoi(argv[i]);
		if (nb < INT_MIN || nb > INT_MAX)
			return (ft_dellist(&head), NULL);
		if (i == 1)
		{
			head = ft_lstnew(nb, head);
			if (head == NULL)
				return (NULL);
		}
		else
		{
			new = malloc(sizeof(t_list));
			if (!new)
				return (ft_dellist(&head), NULL);
			tmp = head;
			ft_lstadd_back(&tmp, new, nb);
		}
		i++;
	}
	if (ft_checkdoubles(i - 1, &tmp) == 1)
		return (ft_dellist(&head), NULL);
	ft_swap_a(&head);
	return ("OK");
}
