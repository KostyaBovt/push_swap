/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_smart_back.c                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:53:39 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 18:53:40 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_smart_back(t_stack *stack_a, t_stack *stack_b, t_med_lst *med_lst)
{
	int		*st_b;
	int		*first_b;
	int		*pack_b;
	int		*size_b;

	st_b = stack_b->stack;
	first_b = &(stack_b->first);
	pack_b = &((stack_b->ordr_lst)->pack);
	size_b = &(stack_b->size);
	while (push_smart_cond(stack_b))
	{
		if (is_max(st_b[*first_b], &(st_b[*first_b]), *pack_b))
			push_smart_back_c1(stack_a, stack_b, med_lst);
		else if (is_max(st_b[*first_b + 1], &(st_b[*first_b]), *pack_b))
			push_smart_back_c2(stack_a, stack_b, med_lst);
		else if (is_ordr_lst_one(stack_b->ordr_lst) \
				&& is_max(st_b[*size_b - 1], &(st_b[*first_b]), *pack_b))
			push_smart_back_c3(stack_a, stack_b, med_lst);
	}
}

int		push_smart_cond(t_stack *st_b)
{
	int		*tab_b;
	int		*first_b;
	int		*pack_b;
	int		*size_b;

	tab_b = st_b->stack;
	first_b = &(st_b->first);
	pack_b = &((st_b->ordr_lst)->pack);
	size_b = &(st_b->size);
	if (*pack_b > 3 && (is_max(tab_b[*first_b], &(tab_b[*first_b]), *pack_b) \
		|| is_max(tab_b[*first_b + 1], &(tab_b[*first_b]), *pack_b) \
		|| (is_ordr_lst_one(st_b->ordr_lst) \
		&& is_max(tab_b[*size_b - 1], &(tab_b[*first_b]), *pack_b))))
		return (1);
	return (0);
}

void	push_smart_back_c1(t_stack *st_a, t_stack *st_b, t_med_lst *m_lst)
{
	apl_apd_cmd(st_a, st_b, "pa\n", m_lst);
	st_a->sorted = st_a->first;
	(st_b->ordr_lst)->pack -= 1;
}

void	push_smart_back_c2(t_stack *st_a, t_stack *st_b, t_med_lst *m_lst)
{
	apl_apd_cmd(st_a, st_b, "sb\n", m_lst);
	apl_apd_cmd(st_a, st_b, "pa\n", m_lst);
	st_a->sorted = st_a->first;
	(st_b->ordr_lst)->pack -= 1;
}

void	push_smart_back_c3(t_stack *st_a, t_stack *st_b, t_med_lst *m_lst)
{
	apl_apd_cmd(st_a, st_b, "rrb\n", m_lst);
	apl_apd_cmd(st_a, st_b, "pa\n", m_lst);
	st_a->sorted = st_a->first;
	(st_b->ordr_lst)->pack -= 1;
}
