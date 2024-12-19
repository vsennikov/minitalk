/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   signal_utils.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 17:28:05 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/19 17:57:48 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "server.h"

char	*transfer_str(char *str, char ch)
{
	int		i;
	char	*new_str;

	i = 0;
	while (str[i])
		i++;
	new_str = malloc((i + 2) * sizeof(char));
	if (!new_str)
	{
		free(str);
		error_exit("failed to allocate memorry for new_str\n", 1);
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

char	*ff_func(char *str, int *bit_i, int *sig1, int *ff)
{
	if (str)
		free(str);
	str = ft_calloc(2, sizeof(char));
	if (!str)
		error_exit("failed to allocate memorry for str", 1);
	*sig1 = 0;
	*bit_i = 0;
	*ff = 0;
	return (str);
}

char	*sig_8_func(char *str, int *sig1, int *bit_i)
{
	if (str)
		free(str);
	str = ft_calloc(2, sizeof(char));
	if (!str)
		error_exit("failed to allocate memorry for str", 1);
	*sig1 = 0;
	*bit_i = 0;
	return (str);
}

char	*bit_i_8_func(char *str, int *sig1, int *bit_i, char ch)
{
	*sig1 = 0;
	*bit_i = 0;
	if (ch == '\0')
	{
		ft_printf("%s", str);
		free(str);
		str = NULL;
	}
	else
		str = transfer_str(str, ch);
	return (str);
}

void	sig1_func(int *ff, int *sig1, int *bit_i, unsigned char *ch)
{
	(*ff)++;
	(*sig1)++;
	(*bit_i)++;
	*ch |= 1;
}
