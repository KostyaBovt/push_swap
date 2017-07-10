/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_tab.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:47:04 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 16:47:05 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

int			count_tabs(char **tab)
{
	int		i;
	int		count;

	i = 0;
	count = 0;
	while (tab[i])
	{
		count++;
		i++;
	}
	return (count);
}

long int	del_tab(char ***tab)
{
	int		i;

	i = -1;
	while ((*tab)[++i])
		free((*tab)[i]);
	free(*tab);
	return (0);
}
