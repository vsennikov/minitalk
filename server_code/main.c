/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:56 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/06 16:35:10 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	signal_handler(int signum)
{
	static int	rows = 0;
	static int	cols = 0;
	static int	sig1 = 0;
	static int	sig2 = 0;

	if (signum == SIGUSR1)
		sig1++;
	if (signum == SIGUSR2)
	{
		sig2++;
		if (sig2 == 1)
			rows = sig1;
		if (sig2 == 2)
		{
			cols = sig1 - rows;
			ft_putchar_fd(rows * 16 + cols, 1);
			sig1 = 0;
			sig2 = 0;
			rows = -1;
			cols = 0;
		}
	}
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server pid: %d\n", pid);
	while (1)
	{
		signal(SIGUSR1, signal_handler);
		signal(SIGUSR2, signal_handler);
	}
	return (0);
}
