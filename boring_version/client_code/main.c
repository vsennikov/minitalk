/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:20:35 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/19 19:08:32 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

char		*g_pid_sig = NULL;

static void	send_bit(int g_pid, unsigned char bit)
{
	if (bit - 48 == 1)
	{
		g_pid_sig = ft_strjoin(g_pid_sig, "1");
		if (!g_pid_sig)
			error_exit("ft_strjoin failed", 1);
		kill(g_pid, SIGUSR1);
	}
	else
	{
		g_pid_sig = ft_strjoin(g_pid_sig, "0");
		if (!g_pid_sig)
			error_exit("ft_strjoin failed", 1);
		kill(g_pid, SIGUSR2);
	}
	usleep(100);
}

static int	send_message(int g_pid, char *msg)
{
	int				i;
	int				j;
	unsigned char	bit;

	j = 0;
	bit = 0;
	while (msg[j])
	{
		i = 8;
		while (i--)
		{
			bit = (msg[j] >> i & 1) + 48;
			send_bit(g_pid, bit);
		}
		j++;
	}
	i = 8;
	while (i--)
	{
		bit = ('\0' >> i & 1) + 48;
		send_bit(g_pid, bit);
	}
	return (1);
}

static void	signal_handler(int signum)
{
	int	i;
	int	pid;
	int	last;

	pid = ft_atoi(g_pid_sig);
	last = g_pid_sig[ft_strlen(g_pid_sig) - 1] - '0';
	if (last == 1)
		i = 15;
	else
		i = 16;
	free(g_pid_sig);
	g_pid_sig = NULL;
	if (signum == SIGINT)
	{
		while (i--)
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		exit(1);
	}
}

static void	main_stuff(int pid, char *msg)
{
	int	i;

	while (1)
	{
		i = 16;
		while (i--)
		{
			kill(pid, SIGUSR1);
			usleep(100);
		}
		if (send_message(pid, msg))
		{
			free(g_pid_sig);
			exit(0);
		}
	}
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		error_exit("You should pass 2 argument", 1);
	if (!argv[1][0] || !argv[2][0])
		error_exit("Some of the arguments are empty", 1);
	pid = ft_atoi(argv[1]);
	g_pid_sig = argv[1];
	g_pid_sig = ft_strjoin(g_pid_sig, "+");
	if (!g_pid_sig)
		error_exit("ft_strjoin failed\n", 1);
	if (pid <= 0)
		error_exit("Invalid pid", 1);
	signal(SIGINT, signal_handler);
	main_stuff(pid, argv[2]);
	return (0);
}
