/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/11 16:01:27 by ekwak             #+#    #+#             */
/*   Updated: 2023/02/03 15:09:56 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strjoin.c
 * @author ekwak (student.42seoul.kr)
 * @brief Concatenate two strings.
 */
#include "libft.h"

/** @brief Concatenate two strings.
 * 
 * @param s1 
 * @param s2 
 * @return char* 
 */
char	*ft_strjoin(char const *s1, char const *s2)
{
	char		*str;
	const int	s1_len = ft_strlen(s1);
	const int	s2_len = ft_strlen(s2);

	if (s1 == 0 || s2 == 0)
		return (NULL);
	str = malloc(sizeof(char) * s1_len + s2_len + 1);
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s1, s1_len + 1);
	ft_strlcpy(str + s1_len, s2, s2_len + 1);
	return (str);
}
