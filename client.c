/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:19:04 by vsenniko          #+#    #+#             */
/*   Updated: 2025/01/09 13:26:26 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

int			g_pid;

static void	send_sequence(int numb, int signal)
{
	while (numb--)
	{
		kill(g_pid, signal);
		usleep(200);
	}
	if (signal == SIGUSR2)
		exit(0);
}

void	send_bit(unsigned char bit)
{
	if (bit - 48 == 1)
		kill(g_pid, SIGUSR1);
	else
		kill(g_pid, SIGUSR2);
	usleep(200);
}

static void	send_message(char *msg)
{
	int				i;
	int				j;
	unsigned char	bit;

	send_sequence(8, SIGUSR1);
	j = 0;
	bit = 0;
	while (msg[j])
	{
		i = 8;
		while (i--)
		{
			bit = (msg[j] >> i & 1) + 48;
			send_bit(bit);
		}
		j++;
	}
	i = 8;
	while (i--)
	{
		bit = ('\0' >> i & 1) + 48;
		send_bit(bit);
	}
}

void	c_handler(int signal, siginfo_t *info, void *s)
{
	(void)s;
	(void)info;
	if (signal == SIGUSR2)
	{
		ft_printf("get confirmation\n");
		exit(1);
	}
	else if (signal == SIGINT)
		send_sequence(16, SIGUSR2);
}

int	main(int argc, char **argv)
{
	struct sigaction	sac;

	if (argc != 3)
		error_exit("You should pass 2 argument", 1);
	if (!argv[1][0] || !argv[2][0])
		error_exit("Some of the arguments are empty", 1);
	g_pid = atoi_wrap(argv[1]);
	ft_printf("pid = %d\n", g_pid);
	if (g_pid <= 0)
		error_exit("Invalid pid", 1);
	sac.sa_sigaction = c_handler;
	sigemptyset(&sac.sa_mask);
	sac.sa_flags = SA_SIGINFO;
	sigaction(SIGUSR2, &sac, NULL);
	sigaction(SIGINT, &sac, NULL);
	send_message(argv[2]);
	while (1)
		pause();
}

int	pid_storage(int pid)
{
	static int our_pid = 0;
	
	if (our_pid == 0)
		our_pid = pid;
	return (our_pid);
}
