/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:22:28 by aalemami          #+#    #+#             */
/*   Updated: 2025/09/04 15:22:28 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	const char	*ptr;
	int			i;

	i = 0;
	while (s[i])
	{
		if (s[i] == (char) c)
		{
			ptr = s + i;
			return ((char *) ptr);
		}
		i++;
	}
	if (s[i] == (char)c)
	{
		ptr = s + i;
		return ((char *)ptr);
	}
	return (NULL);
}
