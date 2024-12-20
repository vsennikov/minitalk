/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: vsenniko <vsenniko@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2024/09/13 11:55:41 by vsenniko          #+#    #+#             */
/*   Updated: 2024/12/20 12:56:58 by vsenniko         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/** 
 * Allocates (with malloc(3)) and returns a new
 * string, which is the result of the concatenation
 * of ’s1’ and ’s2’.
 * 
 * @param s1   
 *  The prefix string.
 * @param s2     
 * The suffix string.
 * 
 * @return
 * The new string.
 * NULL if the allocation fails.
 * 
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i1;
	// size_t	i2;
	char	*res;

	i1 = ft_strlen((char *)s1) + ft_strlen((char *)s2) + 1;
	res = (char *)malloc(i1 * sizeof(char));
	if (res == NULL)
	{
		free((char *)s1);
		return (NULL);
	}
	ft_strlcpy(res, s1, ft_strlen((char *)s1) + 1);
	ft_strlcat(res, s2, i1);
	free((char *)s1);
	return (res);
}
