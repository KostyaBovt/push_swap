/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_gnl.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:44:01 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 16:44:02 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

char		*gnl_to_string(t_gnl_list *list)
{
	char	*string;
	char	*to_free;

	string = ft_strdup("");
	while (list)
	{
		to_free = string;
		string = ft_strjoin2(string, list->line);
		free(to_free);
		list = list->next;
	}
	return (string);
}

char		*ft_strjoin2(char *s1, char *s2)
{
	char	*ret;
	size_t	i;
	size_t	j;

	if (!s1 || !s2)
		return (NULL);
	ret = (char*)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (!ret)
		return (NULL);
	i = 0;
	while (s1[i])
	{
		ret[i] = s1[i];
		i++;
	}
	j = 0;
	while (s2[j])
	{
		ret[i + j] = s2[j];
		j++;
	}
	ret[i + j] = '\0';
	return (ret);
}

void		del_gnl_list(t_gnl_list **head)
{
	t_gnl_list	*buf;
	t_gnl_list	*elem;

	buf = *head;
	while (buf)
	{
		elem = buf;
		buf = buf->next;
		free(elem->line);
		free(elem);
	}
}

t_gnl_list	*new_gnl_elem(char *line)
{
	t_gnl_list	*new_elem;

	new_elem = (t_gnl_list*)malloc(sizeof(t_gnl_list));
	new_elem->line = ft_strdup(line);
	new_elem->next = NULL;
	return (new_elem);
}

void		print_cmds(t_gnl_list *list)
{
	int		count;

	count = 1;
	while (list)
	{
		printf("command #%i : %s\n", count++, list->line);
		list = list->next;
	}
}
