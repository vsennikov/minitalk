/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   client.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:21:08 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/06 16:37:00 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef CLIENT_H
# define CLIENT_H

# include "../libft/libft.h"
# include <signal.h>

void	error_exit(char *msg, int code);

typedef struct s_vorze
{
	int	row;
	int	col;
}		t_vorze;
#endif