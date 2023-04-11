/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test_printf.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/04/11 12:00:28 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/11 12:31:12 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "utils.h"

#ifdef DEBUG_MODE

void	test_printf(char *str, int level)
{
// #ifndef DEBUG_LEVEL
// 	if (level > DEBUG_LEVEL)
// 		printf("%s", str);
// #endif
	printf("%s", str);
}
#endif
#ifndef DEBUG_MODE

void	test_printf(char *str)
{
	(void)str;
}
#endif