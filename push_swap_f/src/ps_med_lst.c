/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_med_lst.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:52:47 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 18:52:48 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_med_lst		*make_all_med_lst(t_stack *stack_a)
{
	t_med_lst	*med_lst;
	t_med_lst	*head_med_lst;
	int			stack_size;
	int			n_med[2];
	int			i;

	med_lst = NULL;
	stack_size = stack_a->size;
	n_med[0] = (stack_size / 2) - (stack_size * 15 / 100);
	n_med[1] = (stack_size / 2) + (stack_size * 15 / 100);
	i = n_med[0] - 1;
	while (++i <= n_med[1])
	{
		if (!med_lst)
		{
			med_lst = new_one_med_lst(i, stack_a);
			head_med_lst = med_lst;
		}
		else
		{
			med_lst->next = new_one_med_lst(i, stack_a);
			med_lst = med_lst->next;
		}
	}
	return (head_med_lst);
}

t_med_lst		*new_one_med_lst(int median, t_stack *stack_a)
{
	t_med_lst	*new_med_lst;

	new_med_lst = (t_med_lst*)malloc(sizeof(t_med_lst));
	new_med_lst->st_size = stack_a->size;
	new_med_lst->med = median;
	new_med_lst->n_cmnds = 0;
	new_med_lst->cmnds = NULL;
	new_med_lst->last_cmnd = NULL;
	new_med_lst->next = NULL;
	return (new_med_lst);
}

void			del_med_lst(t_med_lst **med_lst)
{
	t_med_lst	*temp;

	while (*med_lst)
	{
		temp = (*med_lst)->next;
		if ((*med_lst)->cmnds)
			del_gnl_list(&((*med_lst)->cmnds));
		free(*med_lst);
		*med_lst = temp;
	}
	*med_lst = NULL;
}

void			append_cmnd(char *cmnd, t_med_lst *med_lst)
{
	if (med_lst->cmnds == NULL)
	{
		med_lst->cmnds = new_gnl_elem(cmnd);
		med_lst->last_cmnd = med_lst->cmnds;
	}
	else
	{
		(med_lst->last_cmnd)->next = new_gnl_elem(cmnd);
		med_lst->last_cmnd = (med_lst->last_cmnd)->next;
	}
}

t_med_lst		*min_med_lst(t_med_lst *med_lst)
{
	t_med_lst	*min;

	min = med_lst;
	while (med_lst)
	{
		if (min->n_cmnds > med_lst->n_cmnds)
			min = med_lst;
		med_lst = med_lst->next;
	}
	return (min);
}
