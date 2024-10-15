/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: yurolive <yurolive@student.42madrid.com    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/03/23 19:37:10 by yuolivei          #+#    #+#             */
/*   Updated: 2024/10/15 16:39:55 by yurolive         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../libft.h"

/*Reserva (utilizando malloc(3)) un array de strings resultante
de separar la string ’s’ en substrings utilizando el caracter ’c’
como delimitador. El array debe terminar con un puntero NULL.*/

static int	ft_count_words(const char *s, char c)
{
	int	i;
	int	tr;

	i = 0;
	tr = 0;
	while (*s)
	{
		if (*s != c && tr == 0)
			tr = (i++, 1);
		else if (*s == c)
			tr = 0;
		s++;
	}
	return (i);
}

static char	*ft_split_char(const char *str, int start, int finish, char **split)
{
	char	*word;
	int		i;

	i = 0;
	word = malloc((finish - start + 1) * sizeof(char));
	if (!word)
	{
		while (split[i])
			free(split[i++]);
		free(split);
		return (0);
	}
	while (start < finish)
		word[i++] = str[start++];
	word[i] = '\0';
	return (word);
}

char	*aux_split(char	*new_word, int *index)
{
	*index = -1;
	return (new_word);
}

char	**ft_split(char const *s, char c)
{
	size_t	i;
	size_t	j;
	int		index;
	char	**split;
	char	*new_word;

	split = ft_calloc((ft_count_words(s, c) + 1), sizeof(char *));
	if (!split || !s)
		return (0);
	i = -1;
	j = 0;
	index = -1;
	while (++i <= ft_strlen(s))
	{
		if (s[i] != c && index < 0)
			index = i;
		else if ((s[i] == c || i == ft_strlen(s)) && index >= 0)
		{
			new_word = ft_split_char(s, index, i, split);
			if (!new_word)
				return (0);
			split[j++] = aux_split(new_word, &index);
		}
	}
	return (split[j] = 0, split);
}
