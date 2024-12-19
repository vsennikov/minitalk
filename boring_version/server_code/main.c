/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:56 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/19 19:08:22 by vsenniko         ###   ########.fr       */
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

static void	signal_handler(int signum)
{
	static char				*str = NULL;
	static int				bit_i = 0;
	static unsigned char	ch;
	static int				sig1 = 0;
	static int				ff = 0;

	ch <<= 1;
	if (signum == SIGUSR1)
		sig1_func(&ff, &sig1, &bit_i, &ch);
	else if (signum == SIGUSR2)
	{
		bit_i++;
		ff = 0;
	}
	if (signum == SIGINT)
		handle_sigint(&str);
	if (sig1 == 8)
		str = sig_8_func(str, &sig1, &bit_i);
	if (bit_i == 8)
		str = bit_i_8_func(str, &sig1, &bit_i, ch);
	if (ff == 16)
		str = ff_func(str, &bit_i, &sig1, &ff);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server pid: %d\n", pid);
	signal(SIGUSR1, signal_handler);
	signal(SIGUSR2, signal_handler);
	signal(SIGINT, signal_handler);
	while (1)
		pause();
	return (0);
}
