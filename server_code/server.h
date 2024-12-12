/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:21:08 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/12 17:16:50 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../libft/libft.h"
# include <signal.h>

void		error_exit(char *msg, int code);

typedef struct s_vorze
{
	int		rows;
	int		sig1;
	int		sig2;
	char	*str;
	int		i;
}			t_vorze;
#endif