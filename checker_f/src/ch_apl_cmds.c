/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_apl_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:41:01 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 16:41:03 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	apl_cmds(t_stack *st_a, t_stack *st_b, t_gnl_list *cmds, \
		t_ch_bskt *bskt)
{
	if (bskt->v)
	{
		ft_printf("\n initial stacks_->\n");
		print_stacks(st_a, st_b);
	}
	while (cmds)
	{
		apl_cmd(st_a, st_b, cmds->line);
		if (bskt->v || bskt->d)
		{
			ft_printf("\n %s-->\n", cmds->line);
			print_stacks(st_a, st_b);
		}
		cmds = cmds->next;
	}
}

void	apl_cmd(t_stack *st_a, t_stack *st_b, char *cmd)
{
	if (!ft_strncmp(cmd, "sa", 3))
		swap(st_a);
	if (!ft_strncmp(cmd, "sb", 3))
		swap(st_b);
	if (!ft_strncmp(cmd, "ss", 3))
		if (swap(st_a))
			swap(st_b);
	if (!ft_strncmp(cmd, "ra", 3))
		rotate(st_a);
	if (!ft_strncmp(cmd, "rb", 3))
		rotate(st_b);
	if (!ft_strncmp(cmd, "rr", 3))
		if (rotate(st_a))
			rotate(st_b);
	if (!ft_strncmp(cmd, "rra", 3))
		r_rotate(st_a);
	if (!ft_strncmp(cmd, "rrb", 3))
		r_rotate(st_b);
	if (!ft_strncmp(cmd, "rrr", 3))
		if (r_rotate(st_a))
			r_rotate(st_b);
	if (!ft_strncmp(cmd, "pa", 3))
		push(st_b, st_a);
	if (!ft_strncmp(cmd, "pb", 3))
		push(st_a, st_b);
}
