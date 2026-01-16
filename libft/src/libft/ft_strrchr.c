/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:23:23 by aalemami          #+#    #+#             */
/*   Updated: 2025/09/04 15:23:23 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	const char	*ptr;
	int			i;
	int			flag;

	ptr = NULL;
	i = 0;
	flag = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char) c)
		{
			ptr = s + i;
			flag = 1;
		}
		i++;
	}
	if (s[i] == (char) c)
	{
		ptr = s + i;
		flag = 1;
	}
	if (flag == 1)
		return ((char *) ptr);
	return (NULL);
}
