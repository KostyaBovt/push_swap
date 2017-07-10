/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_get_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:43:28 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 16:43:29 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_gnl_list	*get_cmds(t_ch_bskt **bskt, t_stack *st_a, int *is_empt)
{
	if ((*bskt)->i)
		return (get_cmds_file(bskt));
	if ((*bskt)->d)
		return (get_cmds_debug(bskt, st_a));
	else
		return (get_cmds_stdin(is_empt));
}

t_gnl_list	*get_cmds_file(t_ch_bskt **bskt)
{
	t_gnl_list	*commands;
	int			fd;

	fd = open((*bskt)->i_file, O_RDONLY);
	if (fd == -1)
		return ((t_gnl_list*)error_return0("cannot open \
		file with instructions"));
	if (!(commands = get_inpt_fd(fd)))
		return ((t_gnl_list*)error_return0("file with instructions is empty"));
	if (!check_cmds(&commands))
		return ((t_gnl_list*)error_return0("invalid instractions file"));
	return (commands);
}

t_gnl_list	*get_cmds_debug(t_ch_bskt **bskt, t_stack *st_a)
{
	t_gnl_list	*commands;

	if (!(commands = get_inpt_fd_debug(0, bskt, st_a)))
		return (0);
	return (commands);
}

t_gnl_list	*get_inpt_fd_debug(int fd, t_ch_bskt **bskt, t_stack *st_a)
{
	t_gnl_list	*temp_list;
	char		*temp_str;
	t_stack		*st_b;

	st_b = new_stack_b(st_a->size, st_a->size);
	ft_printf("\n initial stacks_->\n");
	print_stacks(st_a, st_b);
	while (get_next_line(fd, &temp_str) == 1)
	{
		temp_list = new_gnl_elem(temp_str);
		free(temp_str);
		if (!check_cmds(&temp_list))
		{
			del_stack(&st_b);
			return ((t_gnl_list*)error_return0("invalid command"));
		}
		apl_cmds(st_a, st_b, temp_list, *bskt);
		del_gnl_list(&temp_list);
	}
	del_stack(&st_b);
	return (temp_list);
}

t_gnl_list	*get_cmds_stdin(int *is_empt)
{
	t_gnl_list	*commands;

	commands = get_inpt_fd(0);
	if (commands == 0)
	{
		*is_empt = 1;
		return (0);
	}
	*is_empt = 0;
	if (!check_cmds(&commands))
		return ((t_gnl_list*)error_return0("invalid command"));
	return (commands);
}
