/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:18:12 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/02 15:51:45 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strlcat.c
 * @author ekwak (student.42seoul.kr)
 * @brief Concatenate strings with size limit.
 */
#include "libft.h"

/**
 * @brief Concatenate strings with size limit.
 * 
 * @param dst 
 * @param src 
 * @param size 
 * @return size_t 
 */
size_t	ft_strlcat(char *dst, const char *src, size_t size)
{
	size_t			i;
	const size_t	dst_len = ft_strlen(dst);
	const size_t	src_len = ft_strlen(src);

	i = 0;
	if (size <= dst_len)
		return (src_len + size);
	while (src[i] != '\0' && ((dst_len + i) < size - 1))
	{
		dst[dst_len + i] = src[i];
		i++;
	}
	dst[dst_len + i] = '\0';
	return (dst_len + src_len);
}
