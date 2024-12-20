/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:18:56 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/20 13:51:11 by vsenniko         ###   ########.fr       */
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
	static char	*msg = NULL;

	if (signum == SIGINT)
		handle_sigint(&msg);
}

int	main(void)
{
	int	pid;

	pid = getpid();
	ft_printf("Server pid: %d\n", pid);

	while (1)
		pause();
	return (0);
}

// 16 SIG1
// 9 SIG1 1 SIG2 -> ff = 0
// if ch == 11111111 ->ff = 1
// if ff == 1 && new_ch == 11111111 -> ff = 0, start reading
// else send signal to client to resend
//