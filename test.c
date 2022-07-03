/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 11:58:39 by saguesse          #+#    #+#             */
/*   Updated: 2022/07/03 18:14:48 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>

typedef struct s_list
{
	int	nbr;
	struct s_list	*next;
}		t_list;

int	ft_lstsize(t_list *lst)
{
	int	i;

	i = 0;
	while (lst)
	{	
		i++;
		lst = lst->next;
	}
	return (i);
}

void	ft_lstprint(t_list *lst)
{

	while (lst)
	{	
		printf("%d -> ", lst->nbr);
		lst = lst->next;
	}
	printf("NULL\n");
}

t_list	*ft_lstlast(t_list *lst)
{
	if (lst == NULL)
		return (lst);
	else
	{
		while (lst->next != NULL)
			lst = lst->next;
	}
	return (lst);
}

void	ft_lstadd_back(t_list **lst, t_list *new, int nbr)
{
	t_list	*last;

	if ((*lst) == NULL)
		(*lst) = new;
	else
	{
		last = ft_lstlast(*lst);
		last->next = new;
		new->nbr = nbr;
		new->next = NULL;
	}
}

void	ft_lstadd_front(t_list **lst, t_list *new, int nbr)
{
	new->next = (*lst);
	new->nbr = nbr;
	(*lst) = new;
}

void	ft_lstadd_pos(t_list **lst, t_list *new, int nbr, int pos)
{
	pos--;
	while (pos != 1)
	{
		(*lst) = (*lst)->next;
		pos--;
	}
	new->next = (*lst)->next;
	new->nbr = nbr;
	(*lst)->next = new;
}

int	main()
{
	t_list	*head;
	t_list	*new;
	t_list	*ptr;

	head = malloc(sizeof(t_list));
	if (!head)
		return (1);
	head->nbr = 5;
	head->next = NULL;
	
	new = malloc(sizeof(t_list));
	new->nbr = 6;
	head->next = new;
	new->next = NULL;

	new = malloc(sizeof(t_list));
	new->nbr = 8;
	head->next->next = new;
	new->next = NULL;


//	***** add back *****

	ptr = head;
	new = malloc(sizeof(t_list));
	ft_lstadd_back(&ptr, new, 9);
	
//	***** add pos *****
	new = malloc(sizeof(t_list));
	ptr = head;
	ft_lstadd_pos(&ptr, new, 7, 3);

//	***** add front *****
	new = malloc(sizeof(t_list));
	ft_lstadd_front(&head, new, 4);
	ptr = head;
	ft_lstprint(ptr);
	
	printf("size = %d\n", ft_lstsize(head));
	
	return (0);
}
