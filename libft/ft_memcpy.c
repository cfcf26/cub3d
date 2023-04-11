/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memcpy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 08:01:34 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/02 15:46:15 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memcpy.c
 * @author ekwak (ekwak@student.42.fr)
 * @brief Copy n bytes from memory area src to memory area dst.
 */
#include "libft.h"

/**
 * @brief Copy n bytes from memory area src to memory area dst.
 * 
 * @param dst 
 * @param src 
 * @param n 
 * @return void* 
 */
void	*ft_memcpy(void	*dst, const	void *src, size_t n)
{
	size_t			i;
	unsigned char	*cpy_d;
	unsigned char	*cpy_s;

	if (dst == src)
		return (dst);
	i = 0;
	cpy_d = (unsigned char *)dst;
	cpy_s = (unsigned char *)src;
	while (i < n)
	{
		cpy_d[i] = cpy_s[i];
		i++;
	}
	return (cpy_d);
}
