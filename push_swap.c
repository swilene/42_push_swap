/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:52:26 by saguesse          #+#    #+#             */
/*   Updated: 2022/07/21 15:44:21 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

/*int	check_double(char ***nbr)
{
	char	*nb;
	int	i;
	int	j;

	i = 0;
	j = 0;
	nb = nbr[i][j];
	while ()

}*/

/*void	stack_a()
{
	t_list	*head;
	t_list	*new;
	t_list	*ptr;

	head = ft_lstnew(nb);
	ptr = head;
	new = malloc(sizeof(t_list));
	if (!new)
		return (NULL);
	ft_lstadd_back(&ptr, new, nb);
}*/

char	*check_args(int	argc, char ** argv)
{
	int		i;
	int		j;
	char	***nbr;
	ssize_t	nb;

	i = 1;
	j = 0;
	nbr = malloc(sizeof(nbr) * argc);
	if (!nbr)
		return (NULL);
	while (i < argc)
	{
		nbr[j] = ft_split(argv[i], ' ');
		i++;
		j++;
	}
	j = 0;
	while (j < (argc - 1))
	{
		i = 0;
		while (nbr[j][i] != NULL)
		{
			nb = ft_atoi(nbr[j][i]);
			if (nb < INT_MIN || nb > INT_MAX)
				return (NULL);
			printf("%zd\n", nb);
			i++;
		}
		j++;
	}
	return (nbr[0][0]);
}

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
