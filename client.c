/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad < sbaghdad@student.1337.ma>       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:15:19 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/01/13 10:15:58 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	send_char(char c, int pid)
{
	int				i;
	unsigned char	h;

	i = 0;
	while (i < 8)
	{
		if (c & (1 << i))
		{
			kill(pid, SIGUSR1);
		}
		else
			kill(pid, SIGUSR2);
		usleep(600);
		i++;
	}
}

int	check_pid(char *pid)
{
	int	index;

	index = 0;
	while (pid[index])
	{
		if (!ft_strchr("0123456789", pid[index]))
			return (1);
		index++;
	}
	return (0);
}

int	main(int ac, char **av)
{
	int		pid;
	int		i;
	char	*string;

	if (ac != 3 || av[2][0] == '\0' || av[1][0] == '\0')
	{
		ft_printf("Invalid arguments please try again. :)\n");
		return (0);
	}
	if (check_pid(av[1]) == 1)
	{
		ft_printf("Sorry, Invalid PID.");
		return (1);
	}
	pid = ft_atoi(av[1]);
	i = 0;
	string = av[2];
	while (string[i])
	{
		send_char(string[i], pid);
		i++;
	}
	send_char('\n', pid);
	return (0);
}
