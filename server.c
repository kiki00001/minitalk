/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:45:16 by heahn             #+#    #+#             */
/*   Updated: 2021/12/13 20:45:20 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handler(int signal)
{
	static int	i;
	static char	c;

	if (signal == SIGUSR1)
		c += 1 << i;
	i++;
	if (i == 8)
	{
		if (c == '\0')
			ft_putchar('\n');
		else
			ft_putchar(c);
		c = 0;
		i = 0;
	}
}

void	ft_pid(void)
{
	pid_t	pid;

	pid = getpid();
	write(1, "Server PID : ", 13);
	ft_putnbr(pid);
	write(1, "\n", 1);
}

int	main(void)
{
	struct sigaction	sig;

	sig.sa_flags = SA_SIGINFO;
	sig.sa_handler = &handler;
	sigaction(SIGUSR1, &sig, NULL);
	sigaction(SIGUSR2, &sig, NULL);
	ft_pid();
	while (1)
		pause();
	return (0);
}
