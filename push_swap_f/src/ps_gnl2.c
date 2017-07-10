/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_gnl2.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:52:25 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 18:52:26 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		count_gnl_lst(t_gnl_list *list)
{
	int		count;

	count = 0;
	while (list)
	{
		count++;
		list = list->next;
	}
	return (count);
}
