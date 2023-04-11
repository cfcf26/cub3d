/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/07/12 10:40:35 by ekwak             #+#    #+#             */
/*   Updated: 2023/01/02 15:50:02 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

/**
 * @file ft_split.c
 * @author ekwak (student.42seoul.kr)
 * @brief Split the string into an array of strings 
 * using the character as a delimiter.
 */
#include "libft.h"

static	size_t	w_count(char const *s, char c)
{
	size_t	count;
	size_t	i;

	i = 0;
	count = 0;
	while (s[i])
	{
		if (s[i] != c)
		{
			count++;
			while (s[i] && s[i] != c)
				i++;
		}
		else
			i++;
	}
	return (count);
}

static	char	*w_dup(char	const *s, char c)
{
	size_t	i;
	char	*str;

	i = 0;
	while (s[i] && s[i] != c)
		i++;
	str = malloc(sizeof(char) * (i + 1));
	if (str == NULL)
		return (NULL);
	ft_strlcpy(str, s, i + 1);
	return (str);
}

static	char	**ft_freeall(char **str, size_t i)
{
	while (i >= 0)
	{
		free(str[i]);
		i--;
	}
	free(str);
	return (NULL);
}

static char	**ft_dosplit(char const *s, char c, const size_t w_con, char **str)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	while (i < w_con && s[j])
	{
		if (s[j] != c)
		{
			str[i] = w_dup(&(s[j]), c);
			if (str[i] == NULL)
				return (ft_freeall(str, i));
			while (s[j] && s[j] != c)
				j++;
			i++;
		}
		else
			j++;
	}
	str[i] = NULL;
	return (str);
}

/**
 * @brief Split the string into an array of strings 
 * using the character as a delimiter.
 * @param s 
 * @param c 
 * @return char** 
 */
char	**ft_split(char const *s, char c)
{
	char			**str;
	const size_t	w_con = w_count(s, c);

	str = malloc(sizeof(char *) * (w_con + 1));
	if (str == NULL)
		return (NULL);
	ft_dosplit(s, c, w_con, str);
	return (str);
}
