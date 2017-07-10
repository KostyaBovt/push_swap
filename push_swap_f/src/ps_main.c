/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_main.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:52:34 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 18:52:35 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		main(int argc, char **argv)
{
	t_stack		*stack_a;
	t_stack		*stack_b;
	t_ps_bskt	*bskt;

	bskt = new_ps_bskt();
	if (!read_argv(argc, argv, &bskt))
		return (0);
	if (!(stack_a = get_stack(argc, argv, &bskt)))
		return ((long int)del_ps_bskt(&bskt));
	del_ps_bskt(&bskt);
	stack_b = new_stack_b(stack_a->size, stack_a->size);
	if (stack_is_sorted(stack_a))
	{
		del_stack(&stack_b);
		del_stack(&stack_a);
		return (0);
	}
	main_next(stack_a, stack_b);
	return (0);
}

void	main_next(t_stack *st_a, t_stack *st_b)
{
	t_stack		*st_c;
	t_stack		*st_d;
	t_med_lst	*m_lst;
	t_med_lst	*temp_m_lst;

	m_lst = make_all_med_lst(st_a);
	temp_m_lst = m_lst;
	while (temp_m_lst)
	{
		st_c = copy_stack(st_a);
		st_d = copy_stack(st_b);
		sort_ps(st_c, st_d, temp_m_lst);
		temp_m_lst->n_cmnds = count_gnl_lst(temp_m_lst->cmnds);
		temp_m_lst = temp_m_lst->next;
		del_stack(&st_c);
		del_stack(&st_d);
	}
	temp_m_lst = min_med_lst(m_lst);
	print_commands(temp_m_lst->cmnds);
	del_med_lst(&m_lst);
	del_stack(&st_b);
	del_stack(&st_a);
}
