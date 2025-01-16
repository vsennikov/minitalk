/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 14:37:08 by vsenniko          #+#    #+#             */
/*   Updated: 2025/01/06 13:05:48 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "minitalk.h"

void	error_exit(char *msg, int code)
{
	if (code)
		write(2, msg, ft_strlen(msg));
	exit(code);
}

int	atoi_wrap(char *str)
{
	int	i;

	i = 0;
	while (str[i])
	{
		if (str[i] < '0' || str[i] > '9')
			return (-1);
		i++;
	}
	if (i > 10)
		return (-1);
	else if (i == 10)
	{
		if (ft_atoi(str) > 2147483647 || ft_atoi(str) < 1)
			return (-1);
	}
	return (ft_atoi(str));
}
