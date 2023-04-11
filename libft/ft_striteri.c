/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_striteri.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:37:36 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/02 15:51:03 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_striteri.c
 * @author ekwak (student.42seoul.kr)
 * @brief Applies the function f to each character of the string passed
 * as argument, and passing its index as first argument.
 * Each character is passed by address to f to be modified if necessary.
 */
#include "libft.h"

/**
 * @brief Applies the function f to each character of the string passed
 * as argument, and passing its index as first argument.
 * Each character is passed by address to f to be modified if necessary.
 * 
 * @param s 
 * @param f 
 */
void	ft_striteri(char *s, void (*f)(unsigned int, char*))
{
	int	i;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, &s[i]);
		i++;
	}
}
