/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_get_input_fd.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:43:40 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 16:43:41 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_gnl_list	*get_inpt_fd(int fd)
{
	t_gnl_list	*temp_list;
	t_gnl_list	*head_list;
	int			f;
	char		*temp_str;

	f = 0;
	if (get_next_line(fd, &temp_str) == 1)
	{
		f = 1;
		temp_list = (t_gnl_list*)malloc(sizeof(t_gnl_list));
		temp_list->line = ft_strdup(temp_str);
		temp_list->next = NULL;
		head_list = temp_list;
		free(temp_str);
	}
	if (f)
		while (get_next_line(fd, &temp_str) == 1)
		{
			temp_list->next = (t_gnl_list*)malloc(sizeof(t_gnl_list));
			temp_list = temp_list->next;
			temp_list->line = ft_strdup(temp_str);
			temp_list->next = NULL;
			free(temp_str);
		}
	return (f ? head_list : NULL);
}
