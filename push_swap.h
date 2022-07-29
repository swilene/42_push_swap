/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   push_swap.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/03 18:44:36 by saguesse          #+#    #+#             */
/*   Updated: 2022/07/20 19:08:40 by saguesse         ###   ########.fr       */
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
char	**ft_split(char const *s, char c);
char	*ft_substr(char const *s, unsigned int start, size_t len);
ssize_t	ft_atoi(const char *nptr );
void	ft_lstadd_back(t_list **lst, t_list *new, int nb);
void	ft_lstclear(t_list **lst, void (*del)(void *));
int	ft_strcmp(char *s1, char *s2);

#endif
