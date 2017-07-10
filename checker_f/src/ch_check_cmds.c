/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_check_cmds.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:42:40 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 16:42:41 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		check_cmds(t_gnl_list **inpt_commands)
{
	char		commands[12][4];
	int			count;
	int			i;
	t_gnl_list	*temp;

	temp = *inpt_commands;
	if (!(*inpt_commands))
		return (0);
	get_allowed_cmds(commands);
	while (temp)
	{
		count = 0;
		i = -1;
		while (commands[++i][0])
			if (compare_cmd(temp->line, commands[i]))
				count++;
		if (!count)
		{
			del_gnl_list(inpt_commands);
			return (0);
		}
		temp = temp->next;
	}
	return (1);
}

void	get_allowed_cmds(char commands[12][4])
{
	ft_strcpy(commands[0], "sa\0\0");
	ft_strcpy(commands[1], "sb\0\0");
	ft_strcpy(commands[2], "ss\0\0");
	ft_strcpy(commands[3], "pa\0\0");
	ft_strcpy(commands[4], "pb\0\0");
	ft_strcpy(commands[5], "ra\0\0");
	ft_strcpy(commands[6], "rb\0\0");
	ft_strcpy(commands[7], "rr\0\0");
	ft_strcpy(commands[8], "rra\0");
	ft_strcpy(commands[9], "rrb\0");
	ft_strcpy(commands[10], "rrr\0");
	ft_strcpy(commands[11], "\0\0\0\0");
}

int		compare_cmd(char *inpt_command, char *command)
{
	if (ft_strlen(inpt_command) != 2 && \
		ft_strlen(inpt_command) != 3)
		return (0);
	if (ft_strncmp(inpt_command, command, 3))
		return (0);
	return (1);
}
