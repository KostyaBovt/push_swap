/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:44:27 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 16:44:28 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		main(int argc, char **argv)
{
	t_gnl_list	*commands;
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_ch_bskt	*bskt;
	int			is_empty;

	bskt = new_ch_bskt();
	if (!read_argv(argc, argv, &bskt))
		return (0);
	if (!(stack_a = get_stack(argc, argv, &bskt)))
		return ((long int)del_ch_bskt(&bskt));
	if (!(commands = get_cmds(&bskt, stack_a, &is_empty)) && !is_empty)
		if (!del_stack(&stack_a))
			return ((long int)del_ch_bskt(&bskt));
	if (!(bskt->d) && !is_empty)
	{
		stack_b = new_stack_b(stack_a->size, stack_a->size);
		apl_cmds(stack_a, stack_b, commands, bskt);
		del_stack(&stack_b);
		del_gnl_list(&commands);
	}
	print_result(is_sorted(stack_a));
	del_stack(&stack_a);
	return ((long int)del_ch_bskt(&bskt));
}
