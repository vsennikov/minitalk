/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_handler.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/12 18:32:40 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/17 20:56:11 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

static char	*reallocate_str(char *str, char ch)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i])
		i++;
	new_str = malloc(sizeof(char) * i + 2);
	if (!new_str)
	{
		free(str);
		error_exit("failed to allocate mem for new_str\n", 1);
	}
	i = 0;
	while (str[i])
	{
		new_str[i] = str[i];
		i++;
	}
	free(str);
	new_str[i++] = ch;
	new_str[i] = '\0';
	return (new_str);
}

static void	print_msg(char **str, int *sig1, int *sig2, int *rows)
{
	ft_printf("%s", *str);
	free(*str);
	*sig1 = 0;
	*sig2 = 0;
	*rows = 0;
	*str = NULL;
}

static void	handle_sig2_2(int *rows, int *sig1, int *sig2, char **str)
{
	char	ch;

	ch = *rows * 16 + *sig1;
	(*str) = reallocate_str(*str, ch);
	if (ch == '\0')
		print_msg(str, sig1, sig2, rows);
	*sig1 = 0;
	*sig2 = 0;
	*rows = 0;
}

void	handle_sigusr2(int *sig1, int *sig2, int *rows, char **str)
{
	(*sig2)++;
	if (*sig2 == 1 && *str[0] == 0)
		*sig1 = 0;
	if (*sig2 == 2 && *str)
	{
		*rows = *sig1;
		*sig1 = 0;
	}
	if (*sig2 == 3 && *str)
		handle_sig2_2(rows, sig1, sig2, str);
}
