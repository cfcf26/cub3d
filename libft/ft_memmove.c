/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 14:44:23 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/02 15:46:30 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_memmove.c
 * @author ekwak (ekwak@student.42.fr)
 * @brief Copy memory area.
 */
#include "libft.h"

static void	*ft_memmove_front(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = 0;
	while (i < len)
	{
		((unsigned char *)dst)[i] = ((unsigned char *)src)[i];
		i++;
	}
	return (dst);
}

static void	*ft_memmove_rear(void *dst, const void *src, size_t len)
{
	size_t	i;

	i = len;
	while (i)
	{
		((unsigned char *)dst)[i - 1] = ((unsigned char *)src)[i - 1];
		i--;
	}
	return (dst);
}

/**
 * @brief Copy memory area.
 * 
 * @param dst 
 * @param src 
 * @param len 
 * @return void* 
 */
void	*ft_memmove(void *dst, const void *src, size_t len)
{
	if (dst == NULL && src == NULL)
		return (NULL);
	else if ((unsigned char *)dst < (unsigned char *)src)
		return (ft_memmove_front(dst, src, len));
	else
		return (ft_memmove_rear(dst, src, len));
}
