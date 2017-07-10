/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_bskt.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:41:47 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 16:41:48 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_ch_bskt	*new_ch_bskt(void)
{
	t_ch_bskt	*bskt;

	bskt = (t_ch_bskt*)malloc(sizeof(t_ch_bskt));
	bskt->v = 0;
	bskt->c = 0;
	bskt->i = 0;
	bskt->i_file = NULL;
	bskt->s = 0;
	bskt->s_file = NULL;
	bskt->d = 0;
	bskt->stack_i = 0;
	return (bskt);
}

t_ch_bskt	*del_ch_bskt(t_ch_bskt **bskt)
{
	if ((*bskt)->i_file)
		free((*bskt)->i_file);
	if ((*bskt)->s_file)
		free((*bskt)->s_file);
	free(*bskt);
	*bskt = NULL;
	return (0);
}

void		print_bskt(t_ch_bskt *bskt)
{
	ft_printf("v = %i\n", bskt->v);
	ft_printf("c = %i\n", bskt->c);
	ft_printf("i = %i\n", bskt->i);
	ft_printf("i_file = %s\n", bskt->i_file);
	ft_printf("s = %i\n", bskt->s);
	ft_printf("s_file = %s\n", bskt->s_file);
	ft_printf("d = %i\n", bskt->d);
	ft_printf("stack_i = %i\n\n", bskt->stack_i);
}
