/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ch_stack.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: kbovt <marvin@42.fr>                       +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2017/03/07 16:46:39 by kbovt             #+#    #+#             */
/*   Updated: 2017/03/07 16:46:40 by kbovt            ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../includes/checker.h"

t_stack		*new_stack(int size, int first)
{
	t_stack	*new_stack;

	new_stack = (t_stack*)malloc(sizeof(t_stack));
	new_stack->stack = NULL;
	new_stack->size = size;
	new_stack->first = first;
	return (new_stack);
}

t_stack		*new_stack_b(int size, int first)
{
	t_stack	*new_stack;

	new_stack = (t_stack*)malloc(sizeof(t_stack));
	new_stack->stack = (int*)malloc(sizeof(int) * size);
	ft_memset((void*)new_stack->stack, 0, sizeof(int) * size);
	new_stack->size = size;
	new_stack->first = first;
	return (new_stack);
}

t_stack		*del_stack(t_stack **stack)
{
	free((*stack)->stack);
	free(*stack);
	*stack = NULL;
	return (0);
}

t_stack		*copy_stack(t_stack *stack_origin)
{
	t_stack	*stack_new;

	stack_new = (t_stack*)malloc(sizeof(t_stack));
	stack_new->stack = (int*)malloc(sizeof(int) * (stack_origin->size));
	stack_new->size = stack_origin->size;
	stack_new->first = stack_origin->first;
	ft_memset((void*)stack_new->stack, 0, sizeof(int) * (stack_new->size));
	ft_memcpy((void*)stack_new->stack, \
	(void*)stack_origin->stack, sizeof(int) * stack_new->size);
	return (stack_new);
}
