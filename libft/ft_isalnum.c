/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_isalnum.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 07:27:49 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/02 15:42:30 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_isalnum.c
 * @author ekwak (ekwak@student.42seoul.kr)
 * @brief Check if the character is alphanumeric.
 */
#include "libft.h"

/**
 * @brief Check if the character is alphanumeric.
 * 
 * @param c 
 * @return int 
 */
int	ft_isalnum(int c)
{
	if (ft_isalpha(c) || ft_isdigit(c))
		return (1);
	else
		return (0);
}
