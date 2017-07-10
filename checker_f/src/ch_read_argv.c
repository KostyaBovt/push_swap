/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_read_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:44:37 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 16:44:38 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_ch_bskt	*read_argv(int argc, char **argv, t_ch_bskt **bskt)
{
	if (!check_argv(argc, argv, *bskt))
		return (del_ch_bskt(bskt));
	if (!check_bskt(*bskt))
		return (del_ch_bskt(bskt));
	return ((t_ch_bskt *)1);
}

int			check_bskt(t_ch_bskt *bskt)
{
	if (bskt->d && bskt->v)
		return (error_return0("flags d and v are incompatible"));
	if (bskt->d && bskt->i)
		return (error_return0("flags d and i are incompatible"));
	if (bskt->stack_i && bskt->s)
		return (error_return0("too mush arguments - \
		we already are to get stack from file"));
	if (bskt->stack_i == 0 && bskt->s == 0)
		return (error_return0("no arguments for stack"));
	return (1);
}

int			check_argv(int argc, char **argv, t_ch_bskt *bskt)
{
	int		i;

	if (argc <= 1)
		return (error_return0("no arguments"));
	i = 0;
	while (++i < argc)
	{
		if (is_flag(argv[i]))
		{
			if (!check_one_flag(bskt, &i, argc, argv))
				return (0);
			continue ;
		}
		bskt->stack_i = i;
		break ;
	}
	return (1);
}
