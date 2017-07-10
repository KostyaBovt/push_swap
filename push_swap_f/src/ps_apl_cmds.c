/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_apl_cmds.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:50:57 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 18:50:59 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	apl_apd_cmd(t_stack *st_a, t_stack *st_b, \
		char *cmd, t_med_lst *m_lst)
{
	apply_command(st_a, st_b, cmd);
	append_cmnd(cmd, m_lst);
}

void	apply_command(t_stack *stack_a, t_stack *stack_b, char *command)
{
	if (!ft_strncmp(command, "sa\n", 3))
		swap(stack_a);
	if (!ft_strncmp(command, "sb\n", 3))
		swap(stack_b);
	if (!ft_strncmp(command, "ss\n", 3))
		if (swap(stack_a))
			swap(stack_b);
	if (!ft_strncmp(command, "ra\n", 3))
		rotate(stack_a);
	if (!ft_strncmp(command, "rb\n", 3))
		rotate(stack_b);
	if (!ft_strncmp(command, "rr\n", 3))
		if (rotate(stack_a))
			rotate(stack_b);
	if (!ft_strncmp(command, "rra", 3))
		r_rotate(stack_a);
	if (!ft_strncmp(command, "rrb", 3))
		r_rotate(stack_b);
	if (!ft_strncmp(command, "rrr", 3))
		if (r_rotate(stack_a))
			r_rotate(stack_b);
	if (!ft_strncmp(command, "pa\n", 3))
		push(stack_b, stack_a);
	if (!ft_strncmp(command, "pb\n", 3))
		push(stack_a, stack_b);
}
