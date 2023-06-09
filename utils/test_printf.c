/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:00:28 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/11 21:52:44 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#ifdef DEBUG_MODE

void	test_printf(char *str)
{
	printf("%s\n", str);
}
#endif

#ifndef DEBUG_MODE

void	test_printf(char *str)
{
	(void)str;
}
#endif
