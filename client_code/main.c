/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:20:35 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/12 18:26:40 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

static void	send_char(t_vorze *vorze, int pid)
{
	int	i;

	i = 0;
	while (i != vorze->row)
	{
		kill(pid, SIGUSR1);
		usleep(500);
		i++;
	}
	kill(pid, SIGUSR2);
	usleep(500);
	i = 0;
	while (i != vorze->col)
	{
		kill(pid, SIGUSR1);
		usleep(500);
		i++;
	}
	kill(pid, SIGUSR2);
	usleep(500);
}

static void	send_message(int pid, char *msg)
{
	int		i;
	t_vorze	vorze;

	i = 0;
	while (msg[i])
	{
		kill(pid, SIGUSR1);
		usleep(500);
		i++;
	}
	kill(pid, SIGUSR2);
	usleep(500);
	i = 0;
	while (msg[i])
	{
		vorze.row = msg[i] / 16;
		vorze.col = msg[i] % 16;
		send_char(&vorze, pid);
		i++;
	}
	vorze.row = '\0' / 16;
	vorze.col = '\0' % 16;
	send_char(&vorze, pid);
}

int	main(int argc, char **argv)
{
	int	pid;

	if (argc != 3)
		error_exit("You should pass 2 argument", 1);
	if (!argv[1][0] || !argv[2][0])
		error_exit("Some of the arguments are empty", 1);
	pid = ft_atoi(argv[1]);
	if (pid <= 0)
		error_exit("Invalid pid", 1);
	send_message(pid, argv[2]);
	return (0);
}
