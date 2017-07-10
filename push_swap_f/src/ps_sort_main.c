/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_sort_main.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:54:01 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 18:54:02 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

void	sort_ps(t_stack *stack_a, t_stack *stack_b, t_med_lst *med_lst)
{
	while (stack_a->sorted != 0)
	{
		while ((stack_a->sorted - stack_a->first) > 3)
			push_pack(stack_a, stack_b, med_lst);
		if (((stack_a->sorted - stack_a->first) <= 3) \
			&& (stack_b->ordr_lst)->pack <= 3)
			sort_small(stack_a, stack_b, med_lst);
		if (((stack_a->sorted - stack_a->first) <= 3) \
			&& (stack_b->ordr_lst)->pack == 4)
			sort_special(stack_a, stack_b, med_lst);
		if (stack_a->first == stack_a->sorted \
			&& (stack_b->ordr_lst)->pack > 3)
			push_smart_back(stack_a, stack_b, med_lst);
		if (stack_a->first == stack_a->sorted \
			&& (stack_b->ordr_lst)->pack > 3)
			push_pack_back(stack_a, stack_b, med_lst);
	}
}

int		is_max(int num, int *tab, int len)
{
	int		i;

	i = -1;
	while (++i < len)
	{
		if (num < tab[i])
			return (0);
	}
	return (1);
}

int		get_median(int *tab, int size, int *pack_size, t_med_lst *med_lst)
{
	int		*new_tab;
	int		i;
	int		median;

	new_tab = (int*)malloc(sizeof(int) * size);
	i = -1;
	while (++i < size)
		new_tab[i] = tab[i];
	sort_stack(new_tab, 0, size - 1);
	if (med_lst->st_size == size)
	{
		*pack_size = med_lst->med;
		median = new_tab[*pack_size];
		free(new_tab);
		return (median);
	}
	*pack_size = size / 2 + (size % 2) * ((size / 2) % 2);
	median = new_tab[size / 2 + (size % 2) * ((size / 2) % 2)];
	free(new_tab);
	return (median);
}

void	sort_small(t_stack *stack_a, t_stack *stack_b, t_med_lst *med_lst)
{
	sort_small_a(stack_a, stack_b, med_lst);
	stack_a->sorted = stack_a->first;
	sort_small_b(stack_a, stack_b, med_lst);
	stack_a->sorted = stack_a->first;
}

void	sort_special(t_stack *stack_a, t_stack *stack_b, t_med_lst *med_lst)
{
	sort_small_a(stack_a, stack_b, med_lst);
	stack_a->sorted = stack_a->first;
}
