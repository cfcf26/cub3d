/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tolower.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:22:53 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/02 15:54:29 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_tolower.c
 * @author ekwak (student.42seoul.kr)
 * @brief Convert an upper-case letter to the corresponding lower-case letter.
 */
#include "libft.h"

/**
 * @brief Convert an upper-case letter to the corresponding lower-case letter.
 * 
 * @param c 
 * @return int 
 */
int	ft_tolower(int c)
{
	if (c >= 'A' && c <= 'Z')
		c += 32;
	return (c);
}
