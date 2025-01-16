/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 17:09:00 by vsenniko          #+#    #+#             */
/*   Updated: 2025/01/03 13:31:17 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

static char	*transfer_str(char *str, char ch)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i])
		i++;
	new_str = ft_calloc((i + 2), sizeof(char));
	if (!new_str)
	{
		free(str);
		error_exit("ft_calloc for new_str failed\n", 1);
	}
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	new_str[i++] = ch;
	new_str[i] = '\0';
	free(str);
	return (new_str);
}

char	*handle_8_bits(char *str, int *bit_i, char ch, int pid)
{
	*bit_i = 0;
	if (ch == '\0')
	{
		ft_printf("Recieved message:\n%s\n", str);
		free(str);
		str = NULL;
		kill(pid, SIGUSR2);
	}
	else if (str)
		str = transfer_str(str, ch);
	return (str);
}

void	sig1_func(int *sig1, char **msg, int *bit_i, unsigned char *ch)
{
	*sig1 = 0;
	*bit_i = 0;
	*msg = ft_calloc(1, sizeof(char));
	if (!*msg)
		error_exit("ft_calloc failed", 1);
	*ch = 0;
}
