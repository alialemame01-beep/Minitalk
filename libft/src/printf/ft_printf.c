/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/03 21:12:26 by aalemami          #+#    #+#             */
/*   Updated: 2025/09/21 19:21:12 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "ft_printf.h"

int	check_specifier(char c)
{
	return (c == 'c' || c == 's' || c == 'p'
		|| c == 'd' || c == 'i' || c == 'u'
		|| c == 'x' || c == 'X' || c == '%');
}

void	print_specifier(char c, va_list *args, int *i, int *total)
{
	if (c == '%')
		ft_print_c('%', i, total);
	else if (c == 'c')
		ft_print_c(va_arg(*args, int), i, total);
	else if (c == 's')
		ft_print_s(va_arg(*args, char *), i, total);
	else if (c == 'd' || c == 'i')
		ft_print_di(va_arg(*args, int), i, total);
	else if (c == 'u')
		ft_print_u(va_arg(*args, unsigned int), i, total);
	else if (c == 'x' || c == 'X')
	{
		ft_print_xx(va_arg(*args, unsigned int), total, c);
		*i = *i + 1;
	}
	else if (c == 'p')
	{
		ft_print_p(va_arg(*args, void *), total, 0);
		*i = *i + 1;
	}
}

int	ft_printf(const char *str, ...)
{
	va_list	args;
	int		total;
	int		i;

	if (!str)
		return (-1);
	va_start(args, str);
	i = 0;
	total = 0;
	while (str[i])
	{
		if (str[i] != '%')
			ft_print_c(str[i], &i, &total);
		else
		{
			if (check_specifier(str[i + 1]))
				print_specifier(str[++i], &args, &i, &total);
			else
				i++;
		}
	}
	va_end(args);
	return (total);
}
