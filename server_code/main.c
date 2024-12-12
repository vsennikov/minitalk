/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:56 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/12 18:13:43 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

int	g_was_allocated = -1;

static void	handle_sigint(char **str)
{
	if (*str)
		free(*str);
	(*str) = NULL;
	exit(0);
}


static void	handle_sigusr2(int *sig1, int *sig2, int *rows, char **str, int *i)
{
	(*sig2)++;
	if (*sig2 == 1 && g_was_allocated == -1)
	{
		*str = calloc(*sig1, sizeof(char));
		if (!*str)
			error_exit("failed to allocate mem for str\n", 1);
		g_was_allocated = *sig1;
		*sig1 = 0;
		*sig2 = 0;
	}
	if (*sig2 == 1)
	{
		*rows = *sig1;
		*sig1 = 0;
	}
	if (*sig2 == 2)
	{
		(*str)[(*i)++] = *rows * 16 + *sig1;
		*sig1 = 0;
		*sig2 = 0;
		*rows = 0;
	}
}

static void	check_allocation_complete(char **str, int *sig1, int *sig2, int *rows, int *i)
{
	if (*i == g_was_allocated)
	{
		// ft_printf("%s\n", *str);
		// free(*str);
		g_was_allocated = -1;
		*sig1 = 0;
		*sig2 = 0;
		*rows = 0;
		*i = 0;
		*str = NULL;
	}
}

static void	signal_handler(int signum)
{
	static int	rows = 0;
	static int	sig1 = 0;
	static int	sig2 = 0;
	static char	*str = NULL;
	static int	i = 0;

	if (signum == SIGINT)
		handle_sigint(&str);
	else if (signum == SIGUSR1)
		sig1++;
	else if (signum == SIGUSR2)
		handle_sigusr2(&sig1, &sig2, &rows, &str, &i);
	check_allocation_complete(&str, &sig1, &sig2, &rows, &i);
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
