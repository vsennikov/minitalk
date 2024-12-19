/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   server.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/12/05 15:21:08 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/19 17:27:46 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef SERVER_H
# define SERVER_H

# include "../libft/libft.h"
# include <signal.h>

void	error_exit(char *msg, int code);

//handler_utils
char	*transfer_str(char *str, char ch);
char	*ff_func(char *str, int *bit_i, int *sig1, int *ff);
char	*sig_8_func(char *str, int *sig1, int *bit_i);
char	*bit_i_8_func(char *str, int *sig1, int *bit_i, char ch);
void	sig1_func(int *ff, int *sig1, int *bit_i, unsigned char *ch);

#endif