/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: aalemami <aalemami@student.42amman.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2026/01/16 14:35:44 by aalemami          #+#    #+#             */
/*   Updated: 2026/01/16 14:35:44 by aalemami         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdbool.h>
#include "libft.h"

static void	send_signal(int pid, char character)
{
	char	current;
	int		i;

	i = 8;
	current = character;
	while (i > 0)
	{
		i--;
		current = character >> i;
		if (current % 2 == 0)
			kill(pid, SIGUSR2);
		else
			kill(pid, SIGUSR1);
		usleep(700);
	}
}

static bool	check_input_characters(const char *word)
{
	int	length;
	int	i;

	length = ft_strlen(word);
	if ((length == 0) || (length == 1 && (word[0] == '-' || word[0] == '+')))
		return (false);
	i = 0;
	if (word[0] == '-' || word[0] == '+')
		i++;
	while (i < length)
	{
		if (!ft_isdigit(word[i]))
			return (false);
		i++;
	}
	return (true);
}

static bool	check_int_limit(const char *word)
{
	int		length;
	int		i;
	bool	is_negative;

	length = ft_strlen(word);
	i = 0;
	is_negative = word[0] == '-';
	if (is_negative || word[0] == '+')
		i++;
	while (word[i] == '0' && i < length - 1)
		i++;
	if (length - i > 10)
		return (false);
	if (length - i == 10)
	{
		if (is_negative)
			return (ft_strncmp(&word[i], "2147483648", 10) <= 0);
		else
			return (ft_strncmp(&word[i], "2147483647", 10) <= 0);
	}
	return (true);
}

bool	validation(const char *pid_str, int *pid)
{
	if (!check_input_characters(pid_str) || !check_int_limit(pid_str))
		return (false);
	if (atoi(pid_str) <= 0)
		return (false);
	*pid = ft_atoi(pid_str);
	return (true);
}

int	main(int argc, char **argv)
{
	int		pid;
	char	*message;
	int		i;

	if (argc != 3)
	{
		ft_printf("Error: Usage: %s <PID> <message>\n", argv[0]);
		exit(1);
	}
	if (!validation(argv[1], &pid))
	{
		ft_printf("Error: Invalid PID\n");
		exit(1);
	}
	message = argv[2];
	i = 0;
	while (message[i])
	{
		send_signal(pid, message[i]);
		i++;
	}
	send_signal(pid, '\0');
	return (0);
}
