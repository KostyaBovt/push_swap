/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_bskt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:51:14 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 18:51:15 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ps_bskt	*new_ps_bskt(void)
{
	t_ps_bskt	*bskt;

	bskt = (t_ps_bskt*)malloc(sizeof(t_ps_bskt));
	bskt->s = 0;
	bskt->s_file = NULL;
	bskt->stack_i = 0;
	return (bskt);
}

t_ps_bskt	*del_ps_bskt(t_ps_bskt **bskt)
{
	if ((*bskt)->s_file)
		free((*bskt)->s_file);
	free(*bskt);
	*bskt = NULL;
	return (0);
}

void		print_bskt(t_ps_bskt *bskt)
{
	ft_printf("s = %i\n", bskt->s);
	ft_printf("s_file = %s\n", bskt->s_file);
	ft_printf("stack_i = %i\n\n", bskt->stack_i);
}
