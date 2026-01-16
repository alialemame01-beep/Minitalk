/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/08/24 13:36:17 by aalemami          #+#    #+#             */
/*   Updated: 2025/09/04 18:42:01 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	count_words(char const *s, char c)
{
	int	count;
	int	i;

	count = 0;
	i = 0;
	while (s[i])
	{
		while (s[i] == c)
			i++;
		if (s[i] == '\0')
			break ;
		count++;
		while (s[i] && s[i] != c)
			i++;
	}
	return (count);
}

static void	free_all(char **ptr, int count)
{
	int	i;

	i = 0;
	while (i < count)
	{
		free(ptr[i]);
		i++;
	}
	free(ptr);
}

static char	*fill_word(char const *s, char c, char *word, int *i)
{
	int	j;

	j = 0;
	while ((s[*i + j] != c) && s[*i + j])
	{
		word[j] = s[*i + j];
		j++;
	}
	*i = *i + j - 1;
	word[j] = '\0';
	return (word);
}

static int	fill_words(char const *s, char c, char **ptr)
{
	char	*word;
	int		i;
	int		j;
	int		size;

	i = 0;
	j = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			size = 0;
			while (s[i + size] != c && s[i + size])
				size++;
			word = (char *) malloc((size + 1) * sizeof(char));
			if (word == NULL)
			{
				free_all(ptr, j);
				return (-1);
			}
			ptr[j++] = fill_word(s, c, word, &i);
		}
		i++;
	}
	return (j);
}

char	**ft_split(char const *s, char c)
{
	char	**ptr;
	int		j;

	if (!s)
		return (NULL);
	ptr = (char **) malloc((count_words(s, c) + 1) * sizeof(char *));
	if (!ptr)
		return (NULL);
	j = fill_words(s, c, ptr);
	if (j == -1)
		return (NULL);
	ptr[j] = NULL;
	return (ptr);
}
