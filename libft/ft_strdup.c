/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/10 12:15:25 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/02 15:50:36 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strdup.c
 * @author ekwak (student.42seoul.kr)
 * @brief Duplicate a string.
 */
#include "libft.h"

/**
 * @brief Duplicate a string.
 * 
 * @param src 
 * @return char* 
 */
char	*ft_strdup(const char *src)
{
	int		i;
	char	*src_dup;

	src_dup = malloc(sizeof(char) * (ft_strlen(src) + 1));
	if (src_dup == NULL)
		return (NULL);
	i = 0;
	while (src[i])
	{
		src_dup[i] = src[i];
		i++;
	}
	src_dup[i] = '\0';
	return (src_dup);
}
