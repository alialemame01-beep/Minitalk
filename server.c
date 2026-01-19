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

static void	handle_signal(int signal)
{
	static char	*message;
	static char	current_char;
	static int	bit;
	char		*temp;

	if (!message)
	{
		message = ft_strdup("");
		if (!message)
			exit(1);
	}
	current_char = current_char | (signal == SIGUSR1);
	bit++;
	if (bit == 8)
	{
		if (current_char == '\0')
		{
			ft_printf("%s\n", message);
			free(message);
			message = NULL;
		}
		else
		{
			temp = message;
			message = ft_strjoin(message, &current_char);
			free(temp);
		}
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
