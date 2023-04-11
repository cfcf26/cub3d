/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   get_next_line.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: ekwak <ekwak@student.42seoul.kr>           +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/08/21 20:24:32 by ekwak             #+#    #+#             */
/*   Updated: 2023/04/10 22:05:58 by ekwak            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*add_lst(t_list *lst, int fd)
{
	t_list	*nod;

	nod = malloc(sizeof(t_list));
	if (nod == NULL)
		return (NULL);
	nod->size = read(fd, nod->str, BUFFER_SIZE);
	if (nod->size <= 0)
	{
		free(nod);
		return (NULL);
	}
	nod->fd = fd;
	nod->next = lst;
	nod->str[nod->size] = '\0';
	nod->offset = 0;
	return (nod);
}

t_list	*search_fd(t_list **head, int fd)
{
	t_list	*before;
	t_list	*nod;

	before = NULL;
	nod = *head;
	while (nod && nod->fd != fd)
	{
		before = nod;
		nod = nod->next;
	}
	if (nod && before == NULL)
		*head = nod->next;
	if (nod && before != NULL)
		before->next = nod->next;
	if (nod)
		nod->next = NULL;
	else
		nod = add_lst(NULL, fd);
	return (nod);
}

t_list	*search_nl(t_list *nod)
{
	int		i;
	t_list	*temp;

	while (nod)
	{
		i = 0;
		while (nod->str[i] != '\0' && nod->str[i] != '\n')
			i++;
		nod->offset = i;
		if (nod->str[i] == '\n')
			return (nod);
		else
		{
			temp = add_lst(nod, nod->fd);
			if (temp == NULL)
				return (nod);
			else
				nod = temp;
		}
	}
	return (nod);
}

void	keep(t_list	**head, t_list	*nod)
{
	t_list	*lst;
	int		i;

	if (nod->str[nod->offset] == '\0')
		return ;
	lst = malloc(sizeof(t_list));
	if (lst == NULL)
		return ;
	lst->fd = nod->fd;
	i = 0;
	while (nod->offset + 1 + i <= nod->size)
	{
		lst->str[i] = nod->str[nod->offset + 1 + i];
		i++;
	}
	lst->str[i] = '\0';
	lst->size = i;
	lst->offset = 0;
	lst->next = *head;
	*head = lst;
}

char	*get_next_line(int fd)
{
	static t_list	*head;
	t_list			*nod;
	char			*result;

	nod = search_fd(&head, fd);
	nod = search_nl(nod);
	if (nod == NULL)
		return (NULL);
	keep(&head, nod);
	result = make_result(nod);
	if (result == NULL)
		return (NULL);
	return (result);
}
