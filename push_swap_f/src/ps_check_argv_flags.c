/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_check_argv_flags.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:51:31 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 18:51:32 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		check_one_flag(t_ps_bskt *bskt, int *i, int argc, char **argv)
{
	if (!ft_strcmp(argv[*i], "-s"))
		if (!check_s_flag(bskt, i, argc, argv))
			return (0);
	return (1);
}

int		is_flag(char *argumet)
{
	char	allowed_flags[5][3];
	int		i;

	get_allowed_flags(allowed_flags);
	i = -1;
	while (++i < 1)
		if (!ft_strcmp(argumet, allowed_flags[i]))
			return (1);
	return (0);
}

void	get_allowed_flags(char allowed_flags[5][3])
{
	ft_strcpy(allowed_flags[0], "-s\0");
	ft_strcpy(allowed_flags[1], "-s\0");
	ft_strcpy(allowed_flags[2], "-s\0");
	ft_strcpy(allowed_flags[3], "-s\0");
	ft_strcpy(allowed_flags[4], "-s\0");
}

int		check_s_flag(t_ps_bskt *bskt, int *i, int argc, char **argv)
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
