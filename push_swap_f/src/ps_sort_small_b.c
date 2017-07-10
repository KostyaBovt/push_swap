/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small_b.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:54:28 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 18:54:30 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_small_b(t_stack *stack_a, t_stack *stack_b, t_med_lst *med_lst)
{
	if ((stack_b->ordr_lst)->pack == 2)
	{
		if ((stack_b->stack)[stack_b->first] < \
			(stack_b->stack)[stack_b->first + 1])
		{
			apl_apd_cmd(stack_a, stack_b, "sb\n", med_lst);
		}
		del_first_ordr_lst(&(stack_b->ordr_lst));
		apl_apd_cmd(stack_a, stack_b, "pa\n", med_lst);
		apl_apd_cmd(stack_a, stack_b, "pa\n", med_lst);
	}
	if ((stack_b->ordr_lst)->pack == 3)
	{
		sort_small_b_3(stack_a, stack_b, med_lst);
		del_first_ordr_lst(&(stack_b->ordr_lst));
	}
}

void	sort_small_b_3(t_stack *stack_a, t_stack *stack_b, t_med_lst *med_lst)
{
	int		*st_b;
	int		first;

	st_b = stack_b->stack;
	first = stack_b->first;
	if (st_b[first + 2] > st_b[first + 1] && st_b[first + 2] > st_b[first])
	{
		apl_apd_cmd(stack_a, stack_b, "pa\n", med_lst);
		apl_apd_cmd(stack_a, stack_b, "sb\n", med_lst);
		apl_apd_cmd(stack_a, stack_b, "pb\n", med_lst);
	}
	if (st_b[first + 1] > st_b[first + 2] && st_b[first + 1] > st_b[first])
	{
		apl_apd_cmd(stack_a, stack_b, "sb\n", med_lst);
	}
	apl_apd_cmd(stack_a, stack_b, "pa\n", med_lst);
	first = stack_b->first;
	if (st_b[first] < st_b[first + 1])
	{
		apl_apd_cmd(stack_a, stack_b, "sb\n", med_lst);
	}
	apl_apd_cmd(stack_a, stack_b, "pa\n", med_lst);
	apl_apd_cmd(stack_a, stack_b, "pa\n", med_lst);
}
