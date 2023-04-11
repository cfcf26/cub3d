/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_atoi.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/09 22:45:40 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/02 15:41:15 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_atoi.c
 * @author ekwak (ekwak@student.42seoul.kr)
 * @brief Convert string to integer.
 */
#include "libft.h"

static	int	ft_isspace(int c)
{
	if (c == ' ' || c == '\f' || c == '\n'
		|| c == '\r' || c == '\t' || c == '\v')
	{
		return (1);
	}
	return (0);
}

static int	ft_longguard(int flag)
{
	if (flag == -1)
		return (0);
	else
		return (-1);
}

/**
 * @brief Convert string to integer.
 * 
 * @param str 
 * @return int 
 */
int	ft_atoi(const char *str)
{
	long	num;
	int		flag;
	int		i;

	i = 0;
	num = 0;
	flag = 1;
	while (ft_isspace(str[i]))
		i++;
	if (str[i] == '-' || str[i] == '+')
	{
		if (str[i] == '-')
			flag *= -1;
		i++;
	}
	while (ft_isdigit(str[i]))
	{
		num = num * 10 + (str[i] - '0');
		if (num < 0)
			return (ft_longguard(flag));
		i++;
	}
	return (num * flag);
}
