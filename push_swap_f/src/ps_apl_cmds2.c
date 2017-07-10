/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ps_apl_cmds2.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 18:51:03 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 18:51:05 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/push_swap.h"

int		swap(t_stack *stack)
{
	int		temp;

	if (stack->first == stack->size || stack->first == stack->size - 1)
		return (1);
	temp = (stack->stack)[stack->first];
	(stack->stack)[stack->first] = (stack->stack)[stack->first + 1];
	(stack->stack)[stack->first + 1] = temp;
	return (1);
}

int		rotate(t_stack *stack)
{
	int		temp;
	int		i;

	if (stack->first == stack->size || stack->first == stack->size - 1)
		return (1);
	temp = (stack->stack)[stack->first];
	i = stack->first;
	while (i < stack->size - 1)
	{
		(stack->stack)[i] = (stack->stack)[i + 1];
		i++;
	}
	(stack->stack)[stack->size - 1] = temp;
	return (1);
}

int		r_rotate(t_stack *stack)
{
	int		temp;
	int		i;

	if (stack->first == stack->size || stack->first == stack->size - 1)
		return (1);
	temp = (stack->stack)[stack->size - 1];
	i = stack->size - 1;
	while (i > stack->first)
	{
		(stack->stack)[i] = (stack->stack)[i - 1];
		i--;
	}
	(stack->stack)[stack->first] = temp;
	return (1);
}

int		push(t_stack *from, t_stack *to)
{
	if (from->first == from->size || to->first == 0)
		return (1);
	(to->stack)[to->first - 1] = (from->stack)[from->first];
	(to->first) -= 1;
	(from->first) += 1;
	return (1);
}
