/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:44:36 by saguesse          #+#    #+#             */
/*   Updated: 2022/07/31 16:43:26 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef PUSH_SWAP_H
# define PUSH_SWAP_H
# include <unistd.h>
# include <stdio.h>
# include <stdlib.h>
# include <limits.h>

typedef struct s_list
{
	int				nb;
	struct s_list	*next;
}		t_list;

void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
ssize_t	ft_atoi(const char *nptr );
t_list	*ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new, int nb);
t_list	*ft_lstnew(int nbr, t_list *head);
void	ft_dellist(t_list **lst);
char	*check_args(int argc, char **argv);
void	ft_swap_a(t_list **lst);
//void    ft_lstclear(t_list **lst, void (*del)(void *));
//void    ft_lstdelone(t_list *lst, void (*del)(void *));

#endif
