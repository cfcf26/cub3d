/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:24:11 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/02 15:50:20 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strchr.c
 * @author ekwak (student.42seoul.kr)
 * @brief Locate the first occurrence of c in the string s.
 */
#include "libft.h"

/**
 * @brief Locate the first occurrence of c in the string s.
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char	*ft_strchr(const char *s, int c)
{
	size_t		i;
	const char	temp = (char)c;

	i = 0;
	while (s[i])
	{
		if (s[i] == temp)
			return ((char *)&s[i]);
		i++;
	}
	if (temp == '\0' && s[i] == '\0')
		return ((char *)&s[i]);
	return (NULL);
}
