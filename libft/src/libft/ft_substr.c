/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:23:32 by aalemami          #+#    #+#             */
/*   Updated: 2025/09/04 15:23:32 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	get_length(char const *s, unsigned int start, size_t len)
{
	if (start + len > ft_strlen(s))
		return (ft_strlen(s + start));
	else
		return (len);
}

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*ptr;
	int		i;
	int		mall_size;

	if (!s || start >= ft_strlen(s))
		return (ft_strdup(""));
	mall_size = (get_length(s, start, len));
	ptr = malloc(sizeof(char) * (mall_size + 1));
	if (ptr == NULL)
		return (NULL);
	i = 0;
	while (i < mall_size)
	{
		ptr[i] = s[start + i];
		i++;
	}
	ptr[i] = '\0';
	return (ptr);
}
