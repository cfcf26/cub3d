/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/15 19:06:15 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/02 15:52:52 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_strmapi.c
 * @author ekwak (student.42seoul.kr)
 * @brief Applies the function f to each character of the string passed 
 * as argument by giving its index as first argument to create a “fresh” 
 * new string (with malloc(3)) resulting from the successive applications of f.
 */
#include "libft.h"

/**
 * @brief Applies the function f to each character of the string passed 
 * as argument by giving its index as first argument to create a “fresh” 
 * new string (with malloc(3)) resulting from the successive applications of f.
 * 
 * @param s 
 * @param f 
 * @return char* 
 */
char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	size_t			i;
	char			*str;
	const size_t	len = ft_strlen(s);

	if (s == NULL)
		return (NULL);
	i = 0;
	str = malloc(sizeof(char) * (len + 1));
	if (str == NULL)
		return (NULL);
	while (s[i])
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
	return (str);
}
