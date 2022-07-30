/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   check_args.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/30 14:57:48 by saguesse          #+#    #+#             */
/*   Updated: 2022/07/30 17:45:08 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

void	ft_free(char ***nbr, t_list **lst, int j, int i)
{
	while (nbr[j] != NULL)
	{
		while (nbr[j][i] != NULL)
		{
			free(nbr[j][i]);
			i++;
		}
		free(nbr[j]);
		i = 0;
		j++;
	}
	free(nbr);
	if ((*lst) != NULL)
		ft_dellist(lst);
}

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

t_list	*stacka_bis(char ***nbr, int j, int i, t_list *head)
{
	ssize_t	nb;
	t_list	*ptr;
	t_list	*new;

	nb = ft_atoi(nbr[j][i]);
	if (nb < INT_MIN || nb > INT_MAX)
		return (ft_free(nbr, &head, j, i), NULL);
	free(nbr[j][i]);
	if (i == 0 && j == 0)
	{
		head = ft_lstnew(nb);
		if (head == NULL)
			return (ft_free(nbr, &head, j, i), NULL);
	}
	else
	{
		new = malloc(sizeof(t_list));
		if (!new)
			return (ft_free(nbr, &head, j, i), NULL);
		ptr = head;
		ft_lstadd_back(&ptr, new, nb);
	}
	return (head);
}

char	*stacka(char ***nbr, int i, int j, int argc)
{
	int		size;
	t_list	*head;
	t_list	*tmp;
	int 	b;

	size = 0;
	head = NULL;
	while (j < (argc - 1))
	{
		i = 0;
		while (nbr[j][i] != NULL)
		{
			if (i == 0 && j == 0)
				head = stacka_bis(nbr, j, i, head);
			if (stacka_bis(nbr, j, i, head) == NULL)
				return (NULL);
			i++;
			size++;
		}
		free(nbr[j]);
		j++;
	}
	tmp = head;
	b = ft_checkdoubles(size, &tmp);
	printf("b = %d\n", b);
	if (/*ft_checkdoubles(size, &tmp)*/ b == 1)
		return (ft_free(nbr, &head, j, i), NULL);
	return ("ok");
}

char	*check_args(int argc, char **argv)
{
	int		i;
	int		j;
	char	***nbr;

	i = 1;
	j = 0;
	nbr = malloc(sizeof(nbr) * argc);
	if (!nbr)
		return (NULL);
	while (i < argc)
	{
		nbr[j] = ft_split(argv[i], ' ');
		if (nbr[j] == NULL)
			ft_free(nbr, NULL, 0, 0);
		i++;
		j++;
	}
	if (stacka(nbr, 0, 0, argc) == NULL)
		return (NULL);
	free(nbr);
	return ("ok");
}
