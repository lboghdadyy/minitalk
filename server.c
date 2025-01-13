/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: sbaghdad <sbaghdad@student.1337.ma>        +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/08 12:15:30 by sbaghdad          #+#    #+#             */
/*   Updated: 2025/01/09 18:06:48 by sbaghdad         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int sig, siginfo_t *siginfo, void *no)
{
	static int				i;
	static int				pid;
	static unsigned char	b;

	if (pid == 0 || pid != siginfo->si_pid)
	{
		pid = siginfo->si_pid;
		i = 0;
		b = 0;
	}
	if (sig == SIGUSR1)
		b |= (1 << i);
	i++;
	if (i == 8)
	{
		if (b != '\0')
			write(1, &b, 1);
		b = 0;
		i = 0;
	}
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server PID = {%d}\n", getpid());
	sa.sa_sigaction = &handler;
	sa.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	while (1)
		pause();
	return (0);
}
