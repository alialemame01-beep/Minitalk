/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:35:51 by aalemami          #+#    #+#             */
/*   Updated: 2026/01/16 14:35:51 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include "libft.h"

void	handle_signal(int signal)
{
	static char	current_char;
	static int	bit;

	current_char = current_char | (signal == SIGUSR1);
	bit++;
	if (bit == 8)
	{
		if (current_char == '\0')
			ft_printf("\n");
		else
			ft_printf("%c", current_char);
		current_char = 0;
		bit = 0;
	}
	else
		current_char = current_char << 1;
}

int	main(void)
{
	ft_printf("%d\n", getpid());
	signal(SIGUSR1, handle_signal);
	signal(SIGUSR2, handle_signal);
	while (1)
		pause();
	return (0);
}
