/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_print_char_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/08 13:46:51 by aalemami          #+#    #+#             */
/*   Updated: 2025/09/08 16:23:32 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

void	ft_print_xx(unsigned int num, int *total, char flag)
{
	char	*str;

	if (flag == 'x')
		str = "0123456789abcdef";
	else
		str = "0123456789ABCDEF";
	while (num > 15)
	{
		ft_print_xx(num / 16, total, flag);
		num %= 16;
	}
	*total = *total + write(1, &str[num], 1);
}

void	ft_print_p(void *ptr, int *total, int flag)
{
	char				*str;
	unsigned long long	p;

	if (!ptr)
	{
		*total = *total + write(1, "(nil)", 5);
		return ;
	}
	p = (unsigned long long)ptr;
	if (!flag)
		*total = *total + write(1, "0x", 2);
	str = "0123456789abcdef";
	while (p > 15)
	{
		ft_print_p((void *)(p / 16), total, 1);
		p %= 16;
	}
	*total = *total + write(1, &str[p], 1);
}
