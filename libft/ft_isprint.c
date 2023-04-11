/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isprint.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 07:28:14 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/02 15:44:56 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isprint.c
 * @author ekwak (ekwak@student.42.fr)
 * @brief Check if the character is printable.
 */
#include "libft.h"

/**
 * @brief Check if the character is printable.
 * 
 * @param c 
 * @return int 
 */
int	ft_isprint(int c)
{
	if (c >= ' ' && c <= '~')
		return (1);
	else
		return (0);
}
