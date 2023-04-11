/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line_utils.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/09/07 00:54:31 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/10 22:05:53 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_result_len(t_list *nod)
{
	int		result_len;
	t_list	*temp;

	temp = nod;
	result_len = 0;
	while (temp)
	{
		result_len += temp->offset;
		temp = temp->next;
	}
	return (result_len);
}

char	*make_result(t_list *nod)
{
	int		result_len;
	char	*result;

	if (nod->str[0] == '\0' && nod->next == NULL)
	{
		free(nod);
		return (NULL);
	}
	result_len = ft_result_len(nod);
	result = malloc(sizeof(char) * (result_len + 2));
	if (result == NULL)
		return (NULL);
	make_result_2(nod, &result, 0, result_len);
	return (result);
}

void	make_result_2(t_list *nod, char **result, int j, int result_len)
{
	t_list	*temp;
	int		i;

	while (nod)
	{
		i = 0;
		result_len -= nod->offset;
		while (i <= nod->offset && nod->str[i] != '\0')
		{
			(*result)[result_len + i] = nod->str[i];
			i++;
			j++;
		}
		temp = nod->next;
		free(nod);
		nod = temp;
	}
	(*result)[j] = '\0';
	return ;
}
