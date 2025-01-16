/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:18:55 by vsenniko          #+#    #+#             */
/*   Updated: 2025/01/03 13:31:12 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	handle_sigusr1(int *bit_i, int *sig1, unsigned char *ch)
{
	(*bit_i)++;
	*ch |= 1;
	(*sig1)++;
}

void	handle_sigusr2(int *bit_i, int *sig1)
{
	(*bit_i)++;
	*sig1 = 0;
}

void	handle_sigint(char **str)
{
	if (*str)
		free(*str);
	exit(1);
}

void	handler(int signal, siginfo_t *info, void *s)
{
	static char				*msg = NULL;
	static int				bit_i = 0;
	static unsigned char	ch;
	static int				sig1 = 0;

	(void)s;
	ch <<= 1;
	if (signal == SIGUSR1)
		handle_sigusr1(&bit_i, &sig1, &ch);
	else if (signal == SIGUSR2)
		handle_sigusr2(&bit_i, &sig1);
	else if (signal == SIGINT)
		handle_sigint(&msg);
	if (sig1 == 8)
		sig1_func(&sig1, &msg, &bit_i, &ch);
	if (bit_i == 8)
		msg = handle_8_bits(msg, &bit_i, ch, info->si_pid);
}

int	main(void)
{
	struct sigaction	sa;

	ft_printf("Server pid: %d\n", getpid());
	sa.sa_flags = SA_SIGINFO;
	sa.sa_sigaction = handler;
	sigemptyset(&sa.sa_mask);
	sigaction(SIGUSR1, &sa, NULL);
	sigaction(SIGUSR2, &sa, NULL);
	sigaction(SIGINT, &sa, NULL);
	while (1)
		pause();
}
