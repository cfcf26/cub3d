/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:44:57 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/02 15:53:14 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strnstr.c
 * @author ekwak (student.42seoul.kr)
 * @brief Locate the first occurrence of the null-terminated string s2 in the
 * null-terminated string s1, where not more than n characters are searched.
 */
#include "libft.h"

/**
 * @brief Locate the first occurrence of the null-terminated string s2 in the
 * null-terminated string s1, where not more than n characters are searched.
 * 
 * @param s1 
 * @param s2 
 * @param n 
 * @return char* 
 */
char	*ft_strnstr(const char *s1, const char *s2, size_t n)
{
	size_t	i;
	size_t	j;

	i = 0;
	if (s1[0] == '\0' && s2[0] == '\0')
		return ((char *)s1);
	if (s2[0] == '\0')
		return ((char *)s1);
	if (n == 0)
		return (NULL);
	while (i < n && s1[i] != '\0')
	{
		j = 0;
		while (i + j < n && s1[i + j] == s2[j] && s2[j] != '\0')
			j++;
		if (s2[j] == '\0')
			return ((char *)&s1[i]);
		i++;
	}
	return (NULL);
}
