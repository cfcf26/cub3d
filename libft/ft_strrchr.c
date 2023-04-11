/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:27:39 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/02 15:53:41 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strrchr.c
 * @author ekwak (student.42seoul.kr)
 * @brief Locate the last occurrence of c in the string s.
 */
#include "libft.h"

/**
 * @brief Locate the last occurrence of c in the string s.
 * 
 * @param s 
 * @param c 
 * @return char* 
 */
char	*ft_strrchr(const char *s, int c)
{
	int					i;
	const unsigned char	temp = (unsigned char)c;

	i = (int)ft_strlen(s);
	if (c == 0)
		return ((char *)&s[i]);
	while (i >= 0)
	{
		if (s[i] == temp)
			return ((char *)&s[i]);
		i--;
	}
	return (NULL);
}
