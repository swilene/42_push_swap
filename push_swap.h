/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:44:36 by saguesse          #+#    #+#             */
/*   Updated: 2022/08/30 22:57:52 by saguesse         ###   ########.fr       */
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
	int				index;
	int				pos;
	int				pos_wanted;
	int				move_b;
	int				move_a;
	struct s_list	*next;
}		t_list;

int		ft_checkargs(int argc, char **argv, t_list **list_a);
void	ft_pushswap(t_list **list_a, t_list **list_b);
void	ft_lstswap(t_list **lst, int list);
void	ft_bigsize(t_list **list_a, t_list **list_b, int size_a);
t_list	*ft_lstlast(t_list *lst);
int		ft_lstsize(t_list *lst);
void	ft_lstreverse_rotate(t_list **lst, int list);
void	ft_lstrotate(t_list **lst, int list);
void	ft_size3(t_list **list_a);
int		ft_checksorted(t_list *lst);
void	ft_lstpush(t_list **pull, t_list **push, int list);
t_list	*ft_lstbeforelast(t_list *lst);
t_list	*ft_lstmin(t_list *lst);
t_list	*ft_lstmax(t_list *lst);
int		ft_lstposmin_a(t_list *list_a, int pos);
void	ft_lstadd_back(t_list **lst, t_list *new, int nb);
void	ft_lstprint_a(t_list *lst);
void	ft_lstprint_b(t_list *lst);
char	*ft_lstnew(int nbr, t_list **head);
void	ft_dellist(t_list **lst);
void	ft_lstdelone(t_list **lst);
void	ft_putstr_fd(char *s, int fd);
size_t	ft_strlen(const char *s);
ssize_t	ft_atoi(const char *nptr );
int		ft_putnbr(int n);
int		ft_putchar(char c);
void	ft_lstindex(t_list *lst, int size);
void	ft_lstpos(t_list **list_a, t_list **list_b);
void	ft_lstpos_wanted(t_list *list_a, t_list *list_b);
void	ft_lstmoves_costs(t_list **list_a, t_list **list_b);

#endif
