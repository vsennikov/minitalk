/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:56 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/17 21:04:46 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

void	error_exit(char *msg, int code)
{
	if (code)
		write(2, msg, ft_strlen(msg));
	exit(code);
}

static void	handle_sigint(char **str)
{
	if (*str)
		free(*str);
	(*str) = NULL;
	exit(0);
}

static void	handle_new_message(int *rows, int *sig1, int *sig2, char **str)
{
	free(*str);
	*str = NULL;
	*rows = 0;
	*sig1 = 0;
	*sig2 = 0;
	*str = ft_calloc(1, sizeof(char));
	if (!*str)
		error_exit("failed to allocate mem for str\n", 1);
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
	if (sig1 == 20 && str)
		handle_new_message(&rows, &sig1, &sig2, &str);
	else if (sig1 == 20 && !str)
	{
		str = ft_calloc(1, sizeof(char));
		sig1 = 0;
		sig2 = 0;
		rows = 0;
		if (!str)
			error_exit("failed to allocate mem for str\n", 1);
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
		signal(SIGINT, signal_handler);
	}
	return (0);
}
