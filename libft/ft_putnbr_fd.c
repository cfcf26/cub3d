/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 20:14:24 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/02 15:48:04 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_putnbr_fd.c
 * @author ekwak (ekwak@student.42seoul.kr)
 * @brief Output the integer to the given file descriptor.
 */
#include"libft.h"

/**
 * @brief Output the integer to the given file descriptor.
 * 
 * @param n 
 * @param fd 
 */
void	ft_putnbr_fd(int n, int fd)
{
	size_t	i;

	i = 0;
	if (n < 0)
	{
		ft_putchar_fd('-', fd);
		i = (unsigned int)n * -1;
	}
	else
		i = n;
	if (i > 9)
		ft_putnbr_fd(i / 10, fd);
	ft_putchar_fd(i % 10 + '0', fd);
}
