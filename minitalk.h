/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minitalk.h                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/02 12:19:53 by vsenniko          #+#    #+#             */
/*   Updated: 2025/01/06 13:00:07 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINITALK_H
# define MINITALK_H

# include "libft/libft.h"
# include <features.h>
# include <signal.h>
# include <stdlib.h>

void	error_exit(char *msg, int code);
char	*handle_8_bits(char *str, int *bit_i, char ch, int pid);
void	sig1_func(int *sig1, char **msg, int *bit_i, unsigned char *ch);
int		atoi_wrap(char *str);
#endif