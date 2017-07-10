/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_check_argv_flags1.c                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:42:10 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 16:42:11 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int		check_one_flag(t_ch_bskt *bskt, int *i, int argc, char **argv)
{
	if (!ft_strcmp(argv[*i], "-i"))
		if (!check_i_flag(bskt, i, argc, argv))
			return (0);
	if (!ft_strcmp(argv[*i], "-s"))
		if (!check_s_flag(bskt, i, argc, argv))
			return (0);
	if (!ft_strcmp(argv[*i], "-d"))
		if (!check_d_flag(bskt))
			return (0);
	if (!ft_strcmp(argv[*i], "-v"))
		if (!check_v_flag(bskt))
			return (0);
	if (!ft_strcmp(argv[*i], "-c"))
		if (!check_c_flag(bskt))
			return (0);
	return (1);
}

int		is_flag(char *argumet)
{
	char	allowed_flags[5][3];
	int		i;

	get_allowed_flags(allowed_flags);
	i = -1;
	while (++i < 5)
		if (!ft_strcmp(argumet, allowed_flags[i]))
			return (1);
	return (0);
}

void	get_allowed_flags(char allowed_flags[5][3])
{
	ft_strcpy(allowed_flags[0], "-v\0");
	ft_strcpy(allowed_flags[1], "-c\0");
	ft_strcpy(allowed_flags[2], "-i\0");
	ft_strcpy(allowed_flags[3], "-s\0");
	ft_strcpy(allowed_flags[4], "-d\0");
}
