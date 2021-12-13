/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: heahn <heahn@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/11/30 18:45:29 by heahn             #+#    #+#             */
/*   Updated: 2021/12/13 20:48:36 by heahn            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	ft_send_msg(pid_t pid, int c)
{
	int	i;

	i = 0;
	while (i < 8)
	{
		if ((c >> i) & 1)
		{
			if (kill(pid, SIGUSR1) == -1)
				ft_error("client error : Signal transmission failed\n", 42);
		}
		else if (kill(pid, SIGUSR2) == -1)
			ft_error("client error : Signal transmission failed\n", 42);
		i++;
		usleep(100);
	}
}

int	main(int argc, char **argv)
{
	int	i;

	i = 0;
	if (argc == 3)
	{
		while (argv[2][i] != '\0')
			ft_send_msg(ft_atoi(argv[1]), argv[2][i++]);
	}
	else
		ft_error("client error : Num of argc\n", 28);
	return (0);
}
