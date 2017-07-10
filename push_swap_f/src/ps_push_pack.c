/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_push_pack.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:53:27 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 18:53:28 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	push_pack_back(t_stack *stack_a, t_stack *stack_b, t_med_lst *med_lst)
{
	int		size_ap[2];
	int		count_pr[2];
	int		median;

	size_ap[0] = (stack_b->ordr_lst)->pack;
	median = get_median(&((stack_b->stack)[stack_b->first]), \
		size_ap[0], &(size_ap[1]), med_lst);
	size_ap[1] = size_ap[0] - size_ap[1];
	ft_memset((void*)count_pr, 0, sizeof(count_pr));
	while (count_pr[0] < size_ap[1])
	{
		if ((stack_b->stack)[stack_b->first] >= median)
		{
			apl_apd_cmd(stack_a, stack_b, "pa\n", med_lst);
			++count_pr[0];
		}
		else if (++count_pr[1])
			apl_apd_cmd(stack_a, stack_b, "rb\n", med_lst);
	}
	if (!is_ordr_lst_one(stack_b->ordr_lst))
		while (count_pr[1]--)
			apl_apd_cmd(stack_a, stack_b, "rrb\n", med_lst);
	(stack_b->ordr_lst)->pack -= size_ap[1];
}

void	push_pack(t_stack *stack_a, t_stack *stack_b, t_med_lst *med_lst)
{
	int		act_size;
	int		pack_size;
	int		count_pr[2];
	int		median;

	act_size = stack_a->sorted - stack_a->first;
	median = get_median(&((stack_a->stack)[stack_a->first]), \
		act_size, &pack_size, med_lst);
	ft_memset((void*)count_pr, 0, sizeof(count_pr));
	while (count_pr[0] < pack_size)
	{
		if ((stack_a->stack)[stack_a->first] < median)
		{
			apl_apd_cmd(stack_a, stack_b, "pb\n", med_lst);
			count_pr[0]++;
		}
		else if (++count_pr[1])
			apl_apd_cmd(stack_a, stack_b, "ra\n", med_lst);
	}
	if (stack_a->sorted != stack_a->size)
		while (count_pr[1]--)
			apl_apd_cmd(stack_a, stack_b, "rra\n", med_lst);
	add_front_ordr_lst(pack_size, &(stack_b->ordr_lst));
}
