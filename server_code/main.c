/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:56 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/12 18:36:09 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static void	handle_sigint(char **str)
{
	if (*str)
		free(*str);
	(*str) = NULL;
	exit(0);
}

static void	signal_handler(int signum)
{
	static int	rows = 0;
	static int	sig1 = 0;
	static int	sig2 = 0;
	static char	*str = NULL;

	if (signum == SIGINT)
		handle_sigint(&str);
	else if (signum == SIGUSR1)
		sig1++;
	else if (signum == SIGUSR2)
		handle_sigusr2(&sig1, &sig2, &rows, &str);
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
		signal(SIGINT, signal_handler);
	}
	return (0);
}
