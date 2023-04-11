/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 23:12:03 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/02 15:42:11 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_calloc.c
 * @author ekwak (ekwak@student.42seoul.kr)
 * @brief Allocate memory for an array of count elements of size bytes each and
 * return a pointer to the allocated memory. The memory is set to zero.
 */
#include "libft.h"

/**
 * @brief Allocate memory for an array of count elements of size bytes each and
 * return a pointer to the allocated memory. The memory is set to zero.
 * 
 * @param count 
 * @param size 
 * @return void* 
 */
void	*ft_calloc(size_t count, size_t size)
{
	char			*str;
	const size_t	total = count * size;

	str = malloc(total);
	if (str == NULL)
		return (NULL);
	ft_bzero(str, total);
	return ((void *)str);
}
