/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_small_a.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:54:20 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 18:54:22 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_small_a(t_stack *stack_a, t_stack *stack_b, t_med_lst *med_lst)
{
	if (stack_a->first == stack_a->sorted - 2)
		if ((stack_a->stack)[stack_a->first] > \
			(stack_a->stack)[stack_a->first + 1])
			apl_apd_cmd(stack_a, stack_b, "sa\n", med_lst);
	if ((stack_a->first == stack_a->sorted - 3) && \
		stack_a->sorted == stack_a->size)
		sort_small_a_3_ult(stack_a, stack_b, med_lst);
	if (stack_a->first == stack_a->sorted - 3)
		sort_small_a_3(stack_a, stack_b, med_lst);
}

void	sort_small_a_3_ult(t_stack *stack_a, \
		t_stack *stack_b, t_med_lst *med_lst)
{
	int		*st_a;
	int		first;

	st_a = stack_a->stack;
	first = stack_a->first;
	if (st_a[first] > st_a[first + 1] && st_a[first] > st_a[first + 2])
		apl_apd_cmd(stack_a, stack_b, "ra\n", med_lst);
	if (st_a[first + 1] > st_a[first] && st_a[first + 1] > st_a[first + 2])
		apl_apd_cmd(stack_a, stack_b, "rra\n", med_lst);
	if (st_a[first] > st_a[first + 1])
		apl_apd_cmd(stack_a, stack_b, "sa\n", med_lst);
}

void	sort_small_a_3(t_stack *stack_a, t_stack *stack_b, t_med_lst *med_lst)
{
	int		*st_a;
	int		first;

	st_a = stack_a->stack;
	first = stack_a->first;
	if (st_a[first] > st_a[first + 1] && st_a[first] > st_a[first + 2])
		apl_apd_cmd(stack_a, stack_b, "sa\n", med_lst);
	if (st_a[first + 1] > st_a[first] && st_a[first + 1] > st_a[first + 2])
	{
		apl_apd_cmd(stack_a, stack_b, "pb\n", med_lst);
		apl_apd_cmd(stack_a, stack_b, "sa\n", med_lst);
		apl_apd_cmd(stack_a, stack_b, "pa\n", med_lst);
	}
	if (st_a[first] > st_a[first + 1])
		apl_apd_cmd(stack_a, stack_b, "sa\n", med_lst);
}
