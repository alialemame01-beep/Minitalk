/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:21:20 by aalemami          #+#    #+#             */
/*   Updated: 2025/09/04 15:21:20 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	void			*ptr;
	unsigned char	*f;
	size_t			i;

	ptr = NULL;
	i = 0;
	f = (unsigned char *) s;
	while (i < n)
	{
		if (f[i] == (unsigned char) c)
		{
			ptr = f + i;
			break ;
		}
		i++;
	}
	if (ptr != NULL)
		return (ptr);
	return (NULL);
}
