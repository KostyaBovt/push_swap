/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_result.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:44:57 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 16:44:58 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

void	print_result(int flag)
{
	if (flag)
		write(1, "OK\n", 3);
	else
		write(1, "KO\n", 3);
}

int		is_sorted(t_stack *stack)
{
	int		i;

	if (stack->first != 0)
		return (0);
	i = 0;
	while (++i < stack->size)
	{
		if ((stack->stack)[i] <= (stack->stack)[i - 1])
			return (0);
	}
	return (1);
}
