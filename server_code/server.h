/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:21:08 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/12 18:42:49 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../libft/libft.h"
# include <signal.h>

void	error_exit(char *msg, int code);
void	handle_sigusr2(int *sig1, int *sig2, int *rows, char **str);

#endif