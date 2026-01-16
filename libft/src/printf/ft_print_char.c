/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:45:59 by aalemami          #+#    #+#             */
/*   Updated: 2025/09/08 16:31:04 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_c(char c, int *i, int *total)
{
	*total = *total + write (1, &c, 1);
	*i = *i + 1;
}

void	ft_print_s(char *s, int *i, int *total)
{
	if (!s)
	{
		*total = *total + write(1, "(null)", 6);
		*i = *i + 1;
		return ;
	}
	*total = *total + write(1, s, ft_strlen(s));
	*i = *i + 1;
}

void	ft_print_di(int num, int *i, int *total)
{
	char	c;

	if (num == -2147483648)
	{
		*total = *total + (write(1, "-2147483648", 11));
		*i = *i + 1;
		return ;
	}
	if (num < 0)
	{
		*total = *total + write(1, "-", 1);
		num *= -1;
	}
	if (num > 9)
		ft_print_di(num / 10, i, total);
	c = (num % 10) + '0';
	*total = *total + write(1, &c, 1);
	if (num < 10)
		*i = *i + 1;
}

void	ft_print_u(unsigned int num, int *i, int *total)
{
	char	c;

	if (num > 9)
		ft_print_u(num / 10, i, total);
	c = (num % 10) + '0';
	*total = *total + write(1, &c, 1);
	if (num < 10)
		*i = *i + 1;
}
