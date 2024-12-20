/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   error_exit.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/19 19:07:31 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/19 19:07:53 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "client.h"

void	error_exit(char *msg, int code)
{
	if (code)
		write(2, msg, ft_strlen(msg));
	exit(code);
}
