/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_check_argv_flags2.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:42:18 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 16:42:19 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		check_i_flag(t_ch_bskt *bskt, int *i, int argc, char **argv)
{
	if (bskt->i)
		return (error_return0("too much -i flags"));
	if (*i == argc - 1)
		return (error_return0("no file with instractions (-i flag stated)"));
	bskt->i = 1;
	bskt->i_file = ft_strdup(argv[*i + 1]);
	(*i)++;
	return (1);
}

int		check_s_flag(t_ch_bskt *bskt, int *i, int argc, char **argv)
{
	if (bskt->s)
		return (error_return0("too much -s flags"));
	if (*i == argc - 1)
		return (error_return0("no file with stack (-s flag stated)"));
	bskt->s = 1;
	bskt->s_file = ft_strdup(argv[*i + 1]);
	(*i)++;
	return (1);
}

int		check_d_flag(t_ch_bskt *bskt)
{
	if (bskt->d)
		return (error_return0("too much -d flags"));
	bskt->d = 1;
	return (1);
}

int		check_v_flag(t_ch_bskt *bskt)
{
	if (bskt->v)
		return (error_return0("too much -v flags"));
	bskt->v = 1;
	return (1);
}

int		check_c_flag(t_ch_bskt *bskt)
{
	if (bskt->c)
		return (error_return0("too much -c flags"));
	bskt->c = 1;
	return (1);
}
