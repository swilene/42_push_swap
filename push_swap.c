/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:52:26 by saguesse          #+#    #+#             */
/*   Updated: 2022/07/30 15:53:34 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	ft_checkdoubles(int size, t_list **lst)
{
	int	nbr;
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

char	*check_args(int	argc, char ** argv)
{
	int		i;
	int		j;
	int		size;
	char	***nbr;
	ssize_t	nb;
	t_list	*head;
	t_list	*ptr;
	t_list	*new;

	i = 1;
	j = 0;
	nbr = malloc(sizeof(nbr) * argc);
	if (!nbr)
		return (NULL);
	while (i < argc)
	{
		nbr[j] = ft_split(argv[i], ' ');
		if (nbr[j] == NULL)
		{
			while (j >= 0)
			{
				free(nbr[j]);
				j--;
			}
			free(nbr);
			return (NULL);
		}
		i++;
		j++;
	}
	j = 0;
	size = 0;
	head = NULL;
	while (j < (argc - 1))
	{
		i = 0;
		while (nbr[j][i] != NULL)
		{
			nb = ft_atoi(nbr[j][i]);
			free(nbr[j][i]);
			if (nb < INT_MIN || nb > INT_MAX)
			{
				free(nbr);
				ft_dellist(&head);
				return (NULL);
			}
			if (i == 0 && j == 0)
			{
				head = ft_lstnew(nb);
				if (head == NULL)
				{
					ft_dellist(&head);
					return (NULL);
				}
			}
			else
			{
				new = malloc(sizeof(t_list));
				if (!new)
				{
					ft_dellist(&ptr);
					return (NULL);
				}
				ptr = head;
				ft_lstadd_back(&ptr, new, nb);
			}
			i++;
			size++;
		}
		free(nbr[j]);
		j++;
	}
	if (ft_checkdoubles(size, &ptr) == 1)
		return (NULL);
	printf("size = %d\n", size);
	free(nbr);
	ft_dellist(&head);
	return ("ok");
}*/

int	main(int argc, char **argv)
{
	if (argc == 1)
		return (1);
	if (check_args(argc, argv) == NULL)
	{
		ft_putstr_fd("Error\n", 2);
		return (1);
	}
	return (0);
}
