/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:44:36 by saguesse          #+#    #+#             */
/*   Updated: 2022/07/30 15:54:03 by saguesse         ###   ########.fr       */
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
	int	nb;
	struct s_list 	*next;
	struct s_list	*prev;
}		t_list;

void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
char	**ft_split(char *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
ssize_t	ft_atoi(const char *nptr );
t_list  *ft_lstlast(t_list *lst);
void	ft_lstadd_back(t_list **lst, t_list *new, int nb);
t_list  *ft_lstnew(int nbr);
void	ft_dellist(t_list **lst);
char    *check_args(int argc, char **argv);
//void    ft_lstclear(t_list **lst, void (*del)(void *));
//void    ft_lstdelone(t_list *lst, void (*del)(void *));

#endif
