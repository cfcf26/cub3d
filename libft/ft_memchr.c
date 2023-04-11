/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:43:27 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/02 15:45:44 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memchr.c
 * @author ekwak (ekwak@student.42.fr)
 * @brief Locate the first occurrence of c (converted to an unsigned char) in
 * string s.
 */
#include "libft.h"

/**
 * @brief Locate the first occurrence of c (converted to an unsigned char) in
 * string s.
 * 
 * @param s 
 * @param c 
 * @param n 
 * @return void* 
 */
void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t				i;
	unsigned char		*str;
	const unsigned char	temp = (unsigned char)c;

	i = 0;
	str = (unsigned char *)s;
	while (i < n)
	{
		if (str[i] == temp)
			return (&str[i]);
		i++;
	}
	return (NULL);
}
