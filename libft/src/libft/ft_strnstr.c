/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:23:17 by aalemami          #+#    #+#             */
/*   Updated: 2025/09/04 15:23:17 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static char	*find(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	while (big[i] && (i < len))
	{
		j = 0;
		while (big[i] == little[j])
		{
			if ((i == len - 1) && little[j + 1] != '\0')
				return (NULL);
			if (i == len - 1)
				return ((char *)&big[i - j]);
			if (!little[j + 1])
				return ((char *)&big[i - j]);
			i++;
			j++;
		}
		i = i - j;
		i++;
	}
	return (NULL);
}

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	if (!little[0])
		return ((char *) big);
	if (len == 0 || !big[0])
		return (NULL);
	return (find(big, little, len));
}
