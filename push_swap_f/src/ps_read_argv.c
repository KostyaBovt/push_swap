/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_read_argv.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:53:50 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 18:53:51 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

t_ps_bskt	*read_argv(int argc, char **argv, t_ps_bskt **bskt)
{
	if (!check_argv(argc, argv, *bskt))
		return (del_ps_bskt(bskt));
	if (!check_bskt(*bskt))
		return (del_ps_bskt(bskt));
	return ((t_ps_bskt *)1);
}

int			check_bskt(t_ps_bskt *bskt)
{
	if (bskt->stack_i && bskt->s)
		return (error_return0("too mush arguments - \
		we already are to get stack from file"));
	if (bskt->stack_i == 0 && bskt->s == 0)
		return (error_return0("no arguments for stack"));
	return (1);
}

int			check_argv(int argc, char **argv, t_ps_bskt *bskt)
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
