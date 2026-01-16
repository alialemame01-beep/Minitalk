/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/09/07 17:27:51 by aalemami          #+#    #+#             */
/*   Updated: 2025/09/08 18:08:49 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef FT_PRINTF_H
# define FT_PRINTF_H

# include <stdarg.h>
# include <unistd.h>
# include "libft.h"

void	ft_print_c(char c, int *i, int *total);
void	ft_print_s(char *s, int *i, int *total);
void	ft_print_di(int num, int *i, int *total);
void	ft_print_u(unsigned int num, int *i, int *total);
void	ft_print_xx(unsigned int num, int *total, char flag);
void	ft_print_p(void *ptr, int *total, int flag);
int		check_specifier(char c);
void	print_specifier(char c, va_list *args, int *i, int *total);
int		ft_printf(const char *str, ...);

#endif