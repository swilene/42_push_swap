/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: saguesse <marvin@42.fr>                    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/05/13 14:40:46 by saguesse          #+#    #+#             */
/*   Updated: 2022/07/25 16:23:04 by saguesse         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "push_swap.h"

static int	len_word(char const *s, char c, int i)
{
	int	len;

	len = 0;
	while (s[i] != c && s[i])
	{
		i++;
		len++;
	}
	return (len);
}

static int	words(const char *s, char c)
{
	int	i;
	int	nb_words;

	i = 0;
	nb_words = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] != c && s[i])
		{	
			while (s[i] && s[i] != c)
				i++;
			nb_words++;
		}
	}
	return (nb_words);
}

static char	*check_malloc(char **str, int j)
{
	if (!str[j])
	{
		while (j >= 0)
		{
			free(str[j]);
			j--;
		}
		free(str);
		return (NULL);
	}
	return (str[j]);
}

char	**ft_split(char const *s, char c, int *nb_words)
{
	int		nb_words;
	int		i;
	int		j;
	int		len;
	char	**str;

	nb_words = words(s, c);
	i = 0;
	j = 0;
	str = malloc(sizeof(str) * (nb_words + 1));
	if (!str)
		return (NULL);
	while (j < nb_words && s[i])
	{
		while (s[i] == c)
			i++;
		len = len_word(s, c, i);
		str[j] = ft_substr(s, i, len);
		if ((check_malloc(str, j)) == NULL)
			return (NULL);
		j++;
		i += len;
	}
	str[j] = NULL;
	return (str);
}
