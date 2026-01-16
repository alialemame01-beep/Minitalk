/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_itoa.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/04 15:21:12 by aalemami          #+#    #+#             */
/*   Updated: 2025/09/04 15:26:16 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static int	get_size(int n)
{
	int	i;

	if (n == 0)
		return (1);
	i = 0;
	if (n < 0)
		i++;
	while (n != 0)
	{
		n /= 10;
		i++;
	}
	return (i);
}

static void	handle_negative(char *ptr, int *i, long int *m)
{
	if (*m < 0)
	{
		ptr[*i] = '-';
		*i = *i + 1;
		*m = *m * (-1);
	}
}

char	*ft_itoa(int n)
{
	char		*ptr;
	long int	m;
	int			i;
	int			size;

	size = get_size(n);
	i = 0;
	m = n;
	ptr = (char *) malloc(sizeof (char) * (size + 1));
	if (ptr == NULL)
		return (NULL);
	handle_negative(ptr, &i, &m);
	if (n == 0)
		ptr[0] = 0 + '0';
	ptr[size] = '\0';
	while (m != 0)
	{
		ptr[size - 1] = (m % 10) + '0';
		m = m / 10;
		size--;
	}
	return (ptr);
}
